import torchio as tio
from vedo import load, show, Volume

def visualize_nifti(path_to_file, bg=(1,1,1)):
    # Load a NIfTI file
    vol = Volume(path_to_file)

    # Show the volume
    show(vol, bg=bg, zoom=0.5)


# Загрузка nii файла
image = tio.ScalarImage('1.nii.gz')

# Поворот изображения на 90 градусов
transform = tio.Affine(scales=(1,), degrees=(90,), translation=(0, ))
transformed_image = transform(image)

# Сохранение матрицы перехода
transformation_matrix = transformed_image['affine']

# Сохранение получившегося nii файла
transformed_image.save('1_rotated.nii.gz')

visualize_nifti("1.nii.gz")
visualize_nifti("1_rotated.nii.gz")


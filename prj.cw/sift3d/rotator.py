import torchio as tio
import torch
import sys

if len(sys.argv) < 2:
    print("Degree should be passed")

deg = int(sys.argv[1])

# Загрузка nii файла
image = tio.ScalarImage('rotated_by_deg/1_rotated_by_{}.nii.gz') # RAS+

# Поворот изображения на deg градусов вокруг оси x
transform = tio.Affine(scales=(1,), degrees=(deg, 0, 0), translation=(0, 0, 0), center='origin')

# Применяем трансформацию к набору данных
transformed_image = transform(image)

# Сохранение матрицы перехода
transformation_matrix = transformed_image['affine']

# Сохранение получившегося nii файла
transformed_image.save('rotated_by_deg/1_rotated_by_{}.nii.gz'.format(deg))


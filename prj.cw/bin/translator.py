import torchio as tio
import torch
import sys

if len(sys.argv) < 2:
    print("Translation should be passed")

x, y, z = int(sys.argv[1]), int(sys.argv[2]), int(sys.argv[3])

# Загрузка nii файла
image = tio.ScalarImage('1.nii.gz')

# Сдвиг изображения на x, y, z
transform = tio.Affine(scales=(1,), degrees=(0,), translation=(x, y, z))

# Применяем трансформацию к набору данных
transformed_image = transform(image)

# Сохранение матрицы перехода
transformation_matrix = transformed_image['affine']

# Сохранение получившегося nii файла
transformed_image.save('translated_on_val/1_translated_on_{}_{}_{}.nii.gz'.format(x, y, z))


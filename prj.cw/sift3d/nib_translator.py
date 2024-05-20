import sys
import nibabel as nib
import numpy as np

if len(sys.argv) < 2:
    print("Translation should be passed")

x, y, z = int(sys.argv[1]), int(sys.argv[2]), int(sys.argv[3])

# Загрузка NIfTI-файла
nii_img = nib.load('1.nii.gz')
trans_nii_img = nib.load('translated_on_val/1_translated_on_10_10_10.nii.gz')

# Получение заголовка
header = nii_img.header
trans_header = trans_nii_img.header

# Получение матрицы преобразования аффинных координат
affine = header.get_qform()
trans_affine = trans_header.get_qform()

print(trans_affine)

shift_matrix = np.array([
    [1, 0, 0, x],
    [0, 1, 0, y],
    [0, 0, 1, z],
    [0, 0, 0, 1]
])

new_affine = np.dot(affine, shift_matrix)

# print(new_affine)

# # Применение смещения к изображению
# nii_img.set_qform(new_affine)

# # Сохранение измененного изображения
# nib.save(nii_img, 'nib_translated_on_val/1_translated_on_{}_{}_{}.nii.gz'.format(x, y, z))

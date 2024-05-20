
import sys, math
from vedo import show, Volume
import nibabel as nib
import numpy as np

# Загрузка NIfTI-файла
nii_img = nib.load('1.nii.gz')

# Получение заголовка
header = nii_img.header

# Получение матрицы преобразования аффинных координат
affine = header.get_qform()

# Смещение изображения
phi = 60 * math.pi / 180 

rotation_matrix = np.array([ # for 45 degree
    [1, 0, 0, 0], 
    [0, math.cos(phi), math.sin(phi), 0], 
    [0, -math.sin(phi), math.cos(phi), 0],
    [0, 0, 0, 1]
])

shift_matrix = np.array([
    [1, 0, 0, 0],
    [0, 1, 0, 0],
    [0, 0, 1, 0],
    [0, 0, 0, 1]
])

new_affine = np.dot(affine, rotation_matrix)

# Применение смещения к изображению
nii_img.set_qform(new_affine)

# Сохранение измененного изображения
nib.save(nii_img, 'rotated_45.nii.gz')


def visualize_nifti(path_to_file, bg=(1,1,1)):
    vol = Volume(path_to_file)
    show(vol, bg=bg)

visualize_nifti("rotated_45.nii.gz")

import torchio as tio
import torch
import sys

deg = int(sys.argv[1])

# Загрузка nii файла
image = tio.ScalarImage('1.nii.gz')

print(image.get_center())

transformed_image = tio.ScalarImage('rotated_by_deg/1_rotated_by_{}.nii.gz'.format(deg))

print(transformed_image.get_center())


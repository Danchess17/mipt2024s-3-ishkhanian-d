import torch
import torchio
import nibabel as nib
import numpy as np

class MyAffine(torchio.transforms.Transform):
    def __init__(self, matrix):
        super().__init__()
        self.matrix = torch.tensor(matrix)

    def apply_transform(self, sample):
        for image_name, image in sample.items():
            if not isinstance(image, torchio.Image):
                continue
            affine = self.matrix
            image.set_data(torchio.utils.resample_array(image.data, affine))
        return sample

# Создание матрицы аффинного преобразования (пример: поворот на 90 градусов по оси X и сдвиг на (1, 2, 3))
matrix = [[1, 0, 0, 1],
          [0, 0, -1, 2],
          [0, 1, 0, 3],
          [0, 0, 0, 1]]

transform = MyAffine(matrix)

import torch
import torchio
import nibabel as nib
import numpy as np

# Загрузка изображения в формате NIfTI
image_path = '1.nii.gz'
nifti_image = nib.load(image_path)
data = nifti_image.get_fdata()

# Добавление размерности канала для сделать тензор 4D
data = np.expand_dims(data, axis=0)  # Добавляем размерность канала

# Применение аффинного преобразования к изображению
sample = {'image': torchio.ScalarImage(tensor=torch.tensor(data))}
transform = torchio.transforms.RescaleIntensity((0, 1), keys='image')  # Указываем ключ 'image' при создании трансформации
transformed_sample = transform(sample)

# Сохранение результата в формате NIfTI
transformed_data = transformed_sample['image'].data.numpy()
transformed_nifti_image = nib.Nifti1Image(transformed_data[0], nifti_image.affine)  # Извлекаем данные из размерности канала
nib.save(transformed_nifti_image, '1_matrix_rotated.nii')

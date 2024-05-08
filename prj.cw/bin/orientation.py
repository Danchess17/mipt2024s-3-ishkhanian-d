import nibabel as nib

# Загрузить NIfTI-изображение
nii = nib.load('path/to/image.nii.gz')

# Получить информацию о заголовке
header = nii.header

# Получить ориентацию
orientation = header.get('sform_code', header.get('qform_code'))

# Проверить ориентацию
if orientation == 1:
    print('LPS (Левая-Задняя-Верхняя)')
elif orientation == 2:
    print('RAS+ (Правая-Передняя-Верхняя)')
else:
    print('Неизвестная ориентация')
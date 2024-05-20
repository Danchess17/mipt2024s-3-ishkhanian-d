import torchio as tio
import torch
import sys

if len(sys.argv) < 2:
    print("Translation should be passed")

x, y, z = int(sys.argv[1]), int(sys.argv[2]), int(sys.argv[3])

image = tio.ScalarImage('../prj.cw/sift3d/1.nii.gz')

transform = tio.Affine(scales=(1,), degrees=(0,), translation=(x, y, z))
transformed_image = transform(image)
transformation_matrix = transformed_image['affine']

transformed_image.save('translations/1_translated_on_{}_{}_{}.nii.gz'.format(x, y, z))


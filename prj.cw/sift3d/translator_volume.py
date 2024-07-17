import vedo
import nibabel as nib
import sys

if len(sys.argv) < 4:
    print("Translation should be passed")

x, y, z = int(sys.argv[1]), int(sys.argv[2]), int(sys.argv[3])

source = "../prj.cw/sift3d/1.nii.gz"
# source = "1.nii.gz"
volume = vedo.Volume(source)

translated_volume = volume.clone()
translated_volume.shift([x, y, z])
nii_image = nib.Nifti1Image(dataobj=translated_volume.tonumpy(), affine=None)
nib.save(nii_image, 'translations/1_translated_by_{}_{}_{}.nii.gz'.format(x, y, z))

volume.cmap("yellow")

# Test point
point = vedo.Point([0, 100, 0], c='blue')
new_point = point.clone()
new_point.shift([x, y, z])
new_point.color("green")

vp = vedo.show(volume, translated_volume, point, new_point, axes=1, bg='white')



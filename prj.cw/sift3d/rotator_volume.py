import vedo
import nibabel as nib
import sys

if len(sys.argv) < 2:
    print("Translation should be passed")

deg = int(sys.argv[1])

source = "../prj.cw/sift3d/1.nii.gz"
# source = "1.nii.gz"
volume = vedo.Volume(source)

rotation_center = vedo.Point([0, 0, 0], c='red')
rotated_volume = volume.clone()
# rotated_volume.pos(rotated_volume.pos() - rotation_center.pos())
rotated_volume.rotate_x(angle=deg, around=rotation_center.pos())
# rotated_volume.pos(rotated_volume.pos() + rotation_center.pos())


#print(rotated_volume.tonumpy())
#print(rotated_volume.origin())
#print(rotated_volume.center())

nii_image = nib.Nifti1Image(dataobj=rotated_volume.tonumpy(), affine=None)
nib.save(nii_image, 'rotations/1_rotated_by_{}.nii.gz'.format(deg))

volume.cmap("yellow")

# Test point
point = vedo.Point([0, 100, 0], c='blue')
new_point = vedo.Point(point.pos() - rotation_center.pos())
new_point.rotate(angle=deg, axis=[1, 0, 0])
new_point = vedo.Point(new_point.pos() + rotation_center.pos())
new_point.color("green")

vp = vedo.show(volume, rotated_volume, rotation_center, point, new_point, axes=1, bg='white')



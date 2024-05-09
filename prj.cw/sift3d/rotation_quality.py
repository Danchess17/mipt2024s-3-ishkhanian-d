import sys, os
import nibabel as nib

nii = nib.load('1.nii.gz')
print(nii.header)
print('========================================')


if len(sys.argv) < 2:
    print("Degree should be passed")

deg = int(sys.argv[1])

rotator_cmd = "python3 rotator.py {}".format(deg)
bash_rotator_cmd = "python3 bash_rotator.py {}".format(deg)
rotator_matcher_cmd = "python3 rotation_matchreader.py {}".format(deg)

os.system(rotator_cmd)
os.system(bash_rotator_cmd)
os.system(rotator_matcher_cmd)
rotated_nii = nib.load('rotated_on_deg/1_rotated_on_{}.nii.gz'.format(deg))
print(rotated_nii.header)
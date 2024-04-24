import sys
from vedo import show, Volume

def visualize_nifti(path_to_file, bg=(1,1,1)):
    vol = Volume(path_to_file)
    show(vol, bg=bg)

degree = str(sys.argv[1])
mode = "default"
if len(sys.argv) > 2:
    mode = str(sys.argv[2])
    print(mode)

#visualize_nifti("1.nii.gz")
if mode == "default":
    visualize_nifti("rotated_by_deg/1_rotated_by_{}.nii.gz".format(degree))
elif mode == "conc":
    visualize_nifti("concated_volumes/rotations/{}_conc.nii.gz".format(degree))
elif mode == "lines":
    visualize_nifti("volumes_lines/rotations/{}_lines.nii.gz".format(degree))


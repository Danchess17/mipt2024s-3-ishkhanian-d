import sys
from vedo import show, Volume

def visualize_nifti(path_to_file, bg=(1,1,1)):
    vol = Volume(path_to_file)
    show(vol, bg=bg)

x, y, z = str(sys.argv[1]), str(sys.argv[2]), str(sys.argv[3])

mode = "default"
if len(sys.argv) > 4:
    mode = str(sys.argv[4])
    print(mode)

#visualize_nifti("1.nii.gz")
if mode == "default":
    visualize_nifti("translated_on_val/1_translated_on_{}_{}_{}.nii.gz".format(x, y, z))
elif mode == "conc":
    visualize_nifti("concated_volumes/translations/{}_{}_{}_conc.nii.gz".format(x, y, z))
elif mode == "lines":
    visualize_nifti("volumes_lines/translations/{}_{}_{}_lines.nii.gz".format(x, y, z))


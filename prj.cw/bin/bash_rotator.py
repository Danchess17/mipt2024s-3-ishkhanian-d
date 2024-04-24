import os, sys

deg = str(sys.argv[1])

cmd = \
    "./regSift3D 1.nii.gz rotated_by_deg/1_rotated_by_" + deg + ".nii.gz " + \
    "--matches matches/rotations/" + deg + "_matches.csv --transform matrices/rotations/" + \
    deg + "_trans.csv " + "--conc concated_volumes/rotations/" + deg + \
    "_conc.nii.gz --lines volumes_lines/rotations/" + deg + "_lines.nii.gz"

# os.system('cat rotated_by_deg/1_rotated_by_{}.nii.gz'.format(deg))
# os.system('./regSift3D 1.nii.gz rotated_by_deg/1_rotated_by_{}.nii.gz ' + 
# '--matches matches/{}_matches.csv --transform matrices/{}_trans.csv ' + 
# '--conc concated_volumes/{}_conc.nii.gz --lines volumes_lines/{}_lines.nii.gz'.
# format(deg, deg, deg, deg, deg))

os.system(cmd)
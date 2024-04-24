import os, sys

x, y, z = str(sys.argv[1]), str(sys.argv[2]), str(sys.argv[3])
point = "{}_{}_{}".format(x, y, z)

cmd = \
    "./regSift3D 1.nii.gz translated_on_val/1_translated_on_" + point + \
    ".nii.gz " + "--matches matches/translations/" + point + \
    "_matches.csv --transform matrices/translations/" + point + "_trans.csv " + \
    "--conc concated_volumes/translations/" + point + \
    "_conc.nii.gz --lines volumes_lines/translations/" + point + "_lines.nii.gz"

os.system(cmd)
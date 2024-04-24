import sys, os
import nibabel as nib

nii = nib.load('1.nii.gz')
print(nii.header)
print('========================================')


if len(sys.argv) < 2:
    print("Translation should be passed")

x, y, z = int(sys.argv[1]), int(sys.argv[2]), int(sys.argv[3])

treshold = int(sys.argv[4])

translator_cmd = "python3 translator.py {} {} {}".format(x, y, z)
bash_translator_cmd = "python3 bash_translator.py {} {} {}".format(x, y, z)
translator_matcher_cmd = "python3 trans_matchreader.py {} {} {} {}".format(x, y, z, treshold)

os.system(translator_cmd)
os.system(bash_translator_cmd)
os.system(translator_matcher_cmd)

translated_nii = nib.load('translated_on_val/1_translated_on_{}_{}_{}.nii.gz'.format(x, y, z))
print(translated_nii.header)
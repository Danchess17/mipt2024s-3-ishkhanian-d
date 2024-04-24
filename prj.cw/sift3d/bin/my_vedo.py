from vedo import load, show, Volume

# path_nifti_keys = "1_keys.nii.gz"
# path_nifti_1 = "1.nii.gz"
# path_nifti_warped_2 = "2_warped.nii.gz"

# path_stl_2 = "2.stl"
# path_stl_keys = "1_keys.stl"
# path_stl_1 = "1.stl"

# def visualize_stl(path_to_file, bg=(1,1,1), mesh_color=(1,0,0)):
#     # Load an STL file
#     mesh = load(path_to_file)
#     mesh.color(mesh_color)

#     # Show the mesh
#     show(mesh, bg=bg)

def visualize_nifti(path_to_file, bg=(1,1,1), mesh_color=(1,0,0)):
    # Load a NIfTI file
    vol = Volume(path_to_file)

    # Show the volume
    show(vol, bg=bg)



# visualize_nifti("1.nii.gz")
# visualize_nifti("2.nii.gz")
visualize_nifti("lines.nii")
# visualize_nifti(path_nifti_warped_2)

# visualize_stl(path_stl_1)
# visualize_stl(path_stl_keys)
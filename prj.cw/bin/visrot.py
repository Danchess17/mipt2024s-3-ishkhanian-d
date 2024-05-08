# Draw the points transformed by the original transformation and after transformation
# using the incorrect transformation, illustrate the effect of center of rotation.
from mpl_toolkits.mplot3d import Axes3D
import SimpleITK as sitk
import numpy as np

def uniform_random_points(bounds, num_points):
    """
    Generate random (uniform withing bounds) nD point cloud. Dimension is based on the number of pairs in the bounds input.

    Args:
        bounds (list(tuple-like)): list where each tuple defines the coordinate bounds.
        num_points (int): number of points to generate.

    Returns:
        list containing num_points numpy arrays whose coordinates are within the given bounds.
    """
    internal_bounds = [sorted(b) for b in bounds]
    # Generate rows for each of the coordinates according to the given bounds, stack into an array,
    # and split into a list of points.
    mat = np.vstack(
        [np.random.uniform(b[0], b[1], num_points) for b in internal_bounds]
    )
    return list(mat[: len(bounds)].T)


rotationCenter = (10, 10, 10)
rotation = sitk.VersorTransform([0,0,1,0], rotationCenter)

rigid_euler = sitk.Euler3DTransform()
rigid_euler.SetMatrix(rotation.GetMatrix())
rigid_euler.SetCenter(rotation.GetCenter())

rigid_versor = sitk.VersorRigid3DTransform()
rigid_versor.SetRotation(rotation.GetVersor())
#rigid_versor.SetCenter(rotation.GetCenter()) #intentional error

# Sanity check to make sure the transformations are equivalent.
bounds = [(-10,10),(-100,100), (-1000,1000)]
num_points = 10
point_list = uniform_random_points(bounds, num_points)
transformed_point_list = [ rotation.TransformPoint(p) for p in point_list]

euler_errors = target_registration_errors(rigid_euler, point_list, transformed_point_list)
versor_errors = target_registration_errors(rigid_versor, point_list, transformed_point_list)

incorrect_transformed_point_list = [ rigid_versor.TransformPoint(p) for p in point_list]
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
orig = ax.scatter(list(np.array(transformed_point_list).T)[0],
                  list(np.array(transformed_point_list).T)[1],
                  list(np.array(transformed_point_list).T)[2], 
                  marker='o', 
                  color='blue',
                  label='Rotation around specific center')
transformed = ax.scatter(list(np.array(incorrect_transformed_point_list).T)[0],
                         list(np.array(incorrect_transformed_point_list).T)[1],
                         list(np.array(incorrect_transformed_point_list).T)[2], 
                         marker='^', 
                         color='red', 
                         label='Rotation around origin')
plt.legend(loc=(0.0,1.0))

print('Euler\tminError: {:.2f} maxError: {:.2f}'.format(min(euler_errors), max(euler_errors)))
print('Versor\tminError: {:.2f} maxError: {:.2f}'.format(min(versor_errors), max(versor_errors)))
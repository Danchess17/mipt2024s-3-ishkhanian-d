import SimpleITK as sitk
import matplotlib.pyplot as plt
import numpy as np
import sys

def resample(image, transform):
  """
  This function resamples (updates) an image using a specified transform
  :param image: The sitk image we are trying to transform
  :param transform: An sitk transform (ex. resizing, rotation, etc.
  :return: The transformed sitk image
  """
  reference_image = image
  interpolator = sitk.sitkBSpline
  default_value = 0
  
  return sitk.Resample(image, reference_image, transform,
                     interpolator, default_value)


def get_center(img):
  """
  This function returns the physical center point of a 3d sitk image
  :param img: The sitk image we are trying to find the center of
  :return: The physical center point of the image
  """
  width, height, depth = img.GetSize()
  print(width/2, height/2, depth/2)
  return img.TransformIndexToPhysicalPoint((int(np.ceil(width/2)),
                                          int(np.ceil(height/2)),
                                          int(np.ceil(depth/2))))


def rotation3d(image, theta_x, theta_y, theta_z, show=False):
  """
  This function rotates an image across each of the x, y, z axes by theta_x, theta_y, and theta_z degrees
  respectively
  :param image: An sitk MRI image
  :param theta_x: The amount of degrees the user wants the image rotated around the x axis
  :param theta_y: The amount of degrees the user wants the image rotated around the y axis
  :param theta_z: The amount of degrees the user wants the image rotated around the z axis
  :param show: Boolean, whether or not the user wants to see the result of the rotation
  :return: The rotated image
  """
  theta_x = np.deg2rad(theta_x)
  theta_y = np.deg2rad(theta_y)
  theta_z = np.deg2rad(theta_z)
  image_center = get_center(image) # RAS+
  euler_transform = sitk.Euler3DTransform((0, 0, 0), theta_x, theta_y, theta_z, (0, 0, 0))
  print(euler_transform.GetMatrix())
  # print(euler_transform.Get())
  # euler_transform.SetCenter(image_center)
  # euler_transform.SetRotation(theta_x, theta_y, theta_z)
  # euler_transform.SetCenter((0, 0, 0))
  resampled_image = resample(image, euler_transform)
#   print(resampled_image.GetSizeOfPixelComponent())
#   if show:
#     plt.imshow(sitk.GetArrayFromImage(resampled_image)[0])
#     plt.show()
  return resampled_image

if __name__ == "__main__":
  deg = int(sys.argv[1])
  img = sitk.ReadImage("1.nii.gz")
  print(img.GetDirection())
#   img_arr = sitk.GetArrayFromImage(img)[0] # Represents the 0th slice, since numpy swaps the first and third axes default to sitk
#   plt.imshow(img_arr)
#   plt.show()
#   input("Press enter to continue...")
  rot_img = rotation3d(img, deg, 0, 0, show=True)
  rotated_sitk_image = sitk.GetImageFromArray(sitk.GetArrayFromImage(rot_img))
  sitk.WriteImage(rotated_sitk_image, "rotated_by_deg/1_rotated_by_{}.nii.gz".format(deg))
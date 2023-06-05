from PIL import Image
image = Image.open("F:/Cosplayer/test_beauty.png")
import numpy
array = numpy.array(image)
print(array.shape)
print(array)


import numpy as np
import matplotlib.pylab as plt
from scipy.fftpack import fft, fftfreq, fft2
from matplotlib.colors import LogNorm

#Escala de grises obtenido de https://stackoverflow.com/questions/3823752/display-image-as-grayscale-using-matplotlib
#Almaceno laa imagenes 
image1= plt.imread("cara_02_grisesMF.png") #normal
image2= plt.imread("cara_03_grisesMF.png") #feliz
#transformada de Fourier 2d para las imagenes.
imagetrans1= fft2(image1)
imagetrans2= fft2(image2)
#imagen original de en escala de grises
plt.figure()
plt.subplot(1,2,1)
plt.imshow(image1,cmap='gray')
plt.title("Cara_02")
plt.colorbar()

plt.subplot(1,2,2)
plt.imshow(image2,cmap='gray')
plt.title("Cara_03")
plt.colorbar()
plt.savefig("Original.png")
#Espectro de Fourier de las imagenes
plt.figure()
plt.subplot(1,2,1)
plt.imshow(abs(imagetrans1),norm=LogNorm(),cmap='gray')
plt.title("Transformada Cara_02")
plt.colorbar()

plt.subplot(1,2,2)
plt.imshow(abs(imagetrans2),norm=LogNorm(),cmap='gray')
plt.title("Transformada Cara_03")
plt.colorbar()
plt.savefig("Espectro_Fourier.png")
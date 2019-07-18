import numpy as np
import matplotlib.pylab as plt
from scipy.fftpack import fft, fftfreq, fft2, fftshift
from matplotlib.colors import LogNorm

#Escala de grises obtenido de https://stackoverflow.com/questions/3823752/display-image-as-grayscale-using-matplotlib
#Almaceno laa imagenes 
image1= plt.imread("cara_02_grisesMF.png") #normal
image2= plt.imread("cara_03_grisesMF.png") #feliz
#transformada de Fourier 2d para las imagenes.
imagetrans1= fft2(image1)
imagetrans2= fft2(image2)
##frecuencias del espectro de la transformada(.shift)
ceros1= fftshift(imagetrans1)
ceros2= fftshift(imagetrans2)
#imagen original de en escala de grises
plt.figure(figsize=(10,10))
plt.subplot(3,2,1)
plt.imshow(image1,cmap='gray')
plt.title("Cara_02")
plt.colorbar()

plt.subplot(3,2,2)
plt.imshow(image2,cmap='gray')
plt.title("Cara_03")
plt.colorbar()

#Espectro de Fourier de las imagenes
plt.subplot(3,2,3)
plt.imshow(abs(imagetrans1),norm=LogNorm(),cmap='gray')
plt.title("Espectro transformada Cara02")
plt.colorbar()

plt.subplot(3,2,4)
plt.imshow(abs(imagetrans2),norm=LogNorm(),cmap='gray')
plt.title("Espectro transformada Cara03")
plt.colorbar()

#frecuencias del espectro
plt.subplot(3,2,5)
plt.imshow(abs(ceros1),norm=LogNorm(),cmap='gray')
plt.title("Frecuencias del espectroCara_02")
plt.colorbar()

plt.subplot(3,2,6)
plt.imshow(abs(ceros2),norm=LogNorm(),cmap='gray')
plt.title("Frecuencias del espectroCara_03")
plt.colorbar()
plt.savefig("JETAS.png")
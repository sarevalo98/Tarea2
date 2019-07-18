import numpy as np
import matplotlib.pylab as plt
from scipy.fftpack import fft, fftfreq, fft2, fftshift,  ifft2
from matplotlib.colors import LogNorm

#Escala de grises obtenido de https://stackoverflow.com/questions/3823752/display-image-as-grayscale-using-matplotlib
#Almaceno laa imagenes 
image1= plt.imread("cara_02_grisesMF.png") #normal
image2= plt.imread("cara_03_grisesMF.png") #feliz

#transformada de Fourier 2d para las imagenes.
imagetrans1= fft2(image1)
imagetrans2= fft2(image2)
joker1=imagetrans1
joker2=imagetrans2

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
plt.imshow(abs(joker1),norm=LogNorm(),cmap='gray')
plt.title("Espectro transformada Cara02")
plt.colorbar()

plt.subplot(3,2,4)
plt.imshow(abs(joker2),norm=LogNorm(),cmap='gray')
plt.title("Espectro transformada Cara03")
plt.colorbar()

#frecuencias del espectro
plt.subplot(3,2,5)
plt.imshow(abs(ceros1),norm=LogNorm(),cmap='gray')
plt.title("Frecuencias del espectro Cara_02")
plt.colorbar()

plt.subplot(3,2,6)
plt.imshow(abs(ceros2),norm=LogNorm(),cmap='gray')
plt.title("Frecuencias del espectro Cara_03")
plt.colorbar()
plt.savefig("Parte1.png")

#Filtros
filtro1=np.where(imagetrans1>90)
filtro2=np.where(imagetrans2<10)
imagetrans1[filtro1]=0
imagetrans2[filtro2]=0

#transformada inversa de las imagenes filtradas
ffinal1 = ifft2(imagetrans1)
ffinal2 = ifft2(imagetrans2)
superpos = np.real(ffinal1)+np.real(ffinal2)

#Filtros de la imagen
plt.figure(figsize=(10,10))
plt.subplot(1,2,1)
plt.imshow(np.abs(imagetrans1),norm=LogNorm(),cmap='gray')
plt.title("Filtro Cara_02")
plt.colorbar()

plt.subplot(1,2,2)
plt.imshow(np.abs(imagetrans2),cmap='gray')
plt.title("Filtro Cara_03")
plt.colorbar()

plt.subplot(1,3,1)
plt.imshow(np.real(ffinal1),cmap='gray')
plt.title("Cara_02 filtrada")
plt.subplot(1,3,2)
plt.imshow(np.real(ffinal2),cmap='gray')
plt.title("Cara_03 filtrada")
plt.subplot(1,3,3)
plt.imshow(superpos,cmap='gray')
plt.title("Superposición de las imagenes")
plt.savefig("Parte2.png")
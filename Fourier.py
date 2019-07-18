import numpy as np
import matplotlib.pylab as plt
from scipy.fftpack import fft, fftfreq, fft2, fftshift,  ifft2, ifftshift
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


#Espectro de Fourier de las imagenes
plt.figure(figsize=(10,10))
plt.subplot(1,2,1)
plt.imshow(abs(imagetrans1),norm=LogNorm())
plt.title("Espectro transformada Cara02")
plt.colorbar()

plt.subplot(1,2,2)
plt.imshow(abs(imagetrans2),norm=LogNorm())
plt.title("Espectro transformada Cara03")
plt.colorbar()
plt.savefig("FFtIm.pdf")

#frecuencias del espectro
plt.figure(figsize=(10,10))
plt.subplot(2,2,1)
plt.imshow(abs(ceros1),norm=LogNorm())
plt.title("Frecuencias del espectro Cara_02")
plt.colorbar()

plt.subplot(2,2,2)
plt.imshow(abs(ceros2),norm=LogNorm())
plt.title("Frecuencias del espectro Cara_03")
plt.colorbar()
#Filtros
filtro1=np.where(abs(ceros1)>40)
filtro2=np.where(abs(ceros2)<90)
ceros1[filtro1]=0
ceros2[filtro2]=0

#transformada inversa de las imagenes filtradas
ffinal1 = ifftshift(ceros1)
ffinal2 = ifftshift(ceros2)
supe1 = ifft2(ffinal1)
supe2 = ifft2(ffinal2)
imafinal=supe1 + supe2

plt.subplot(2,2,3)
plt.imshow(abs(supe1),cmap='gray')
plt.title("Cara_02 filtrada")
plt.colorbar()
plt.subplot(2,2,4)
plt.imshow(abs(supe2),cmap='gray')
plt.title("Cara_03 filtrada")
plt.colorbar()
plt.savefig("ImProceso.pdf")

plt.figure()
plt.imshow(abs(imafinal),cmap='gray')
plt.title("Superposición de las imagenes")
plt.savefig("ImHybrid.pdf")
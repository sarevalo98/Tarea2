import numpy as np
import matplotlib.pylab as plt
from scipy.fftpack import fft, fftfreq, fft2
from matplotlib.colors import LogNorm
######## Almacene la imagen arbol.png
image= plt.imread("cara_02_grisesMF.png")
image2= plt.imread("cara_03_grisesMF.png")
######## Haga la transformada de Fourier 2d usando los paquetes de scipy.
imagetrans= fft2(image)
imagetrans2= fft2(image2)
######## Grafique el espectro de Fourier de la imagen. Guarde la grafica sin mostrarla en FFT2D.png
plt.figure()
plt.subplot(1,2,1)
plt.imshow(abs(imagetrans),norm=LogNorm())
plt.colorbar()

plt.subplot(1,2,2)
plt.imshow(abs(imagetrans),norm=LogNorm())
plt.colorbar()
plt.savefig("Transformada.png")
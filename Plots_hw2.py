import numpy as np
import matplotlib.pylab as plt

datos=np.genfromtxt("Euler.dat",delimiter=" ")
T=datos[:,0]
x=datos[:,1]
y=datos[:,3]
vx=datos[:,2]
vy=datos[:,4]
plt.figure()
plt.plot(x,y)
plt.savefig("ORBITAEULER.png")

datos2=np.genfromtxt("LeapFrog.dat",delimiter=" ")
T2=datos2[:,0]
x2=datos2[:,1]
y2=datos2[:,3]
vx2=datos2[:,2]
vy2=datos2[:,4]
plt.figure()
plt.plot(x2,y2)
plt.savefig("ORBITALEAPFROG.png")

datos3=np.genfromtxt("RungeKutta.dat",delimiter=" ")
T3=datos3[:,0]
x3=datos3[:,1]
y3=datos3[:,3]
vx3=datos3[:,2]
vy3=datos3[:,4]
plt.figure()
plt.plot(x3,y3)
plt.savefig("ORBITARUNGEKUTTA.png")
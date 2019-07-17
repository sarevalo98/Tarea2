import numpy as np
import matplotlib.pylab as plt

datos=np.genfromtxt("Euler.dat",delimiter=" ")
T=datos[:,0]
x=datos[:,1]
y=datos[:,3]
vx=datos[:,2]
vy=datos[:,4]

datos2=np.genfromtxt("LeapFrog.dat",delimiter=" ")
T2=datos2[:,0]
x2=datos2[:,1]
y2=datos2[:,3]
vx2=datos2[:,2]
vy2=datos2[:,4]

datos3=np.genfromtxt("RungeKutta.dat",delimiter=" ")
T3=datos3[:,0]
x3=datos3[:,1]
y3=datos3[:,3]
vx3=datos3[:,2]
vy3=datos3[:,4]

datos4=np.genfromtxt("Euler1.dat",delimiter=" ")
T4=datos4[:,0]
x4=datos4[:,1]
y4=datos4[:,3]
vx4=datos4[:,2]
vy4=datos4[:,4]

datos5=np.genfromtxt("LeapFrog1.dat",delimiter=" ")
T5=datos5[:,0]
x5=datos5[:,1]
y5=datos5[:,3]
vx5=datos5[:,2]
vy5=datos5[:,4]

datos6=np.genfromtxt("RungeKutta1.dat",delimiter=" ")
T6=datos6[:,0]
x6=datos6[:,1]
y6=datos6[:,3]
vx6=datos6[:,2]
vy6=datos6[:,4]

datos7=np.genfromtxt("Euler2.dat",delimiter=" ")
T7=datos7[:,0]
x7=datos7[:,1]
y7=datos7[:,3]
vx7=datos7[:,2]
vy7=datos7[:,4]

datos8=np.genfromtxt("LeapFrog2.dat",delimiter=" ")
T8=datos8[:,0]
x8=datos8[:,1]
y8=datos8[:,3]
vx8=datos8[:,2]
vy8=datos8[:,4]

datos9=np.genfromtxt("RungeKutta2.dat",delimiter=" ")
T9=datos9[:,0]
x9=datos9[:,1]
y9=datos9[:,3]
vx9=datos9[:,2]
vy9=datos9[:,4]

plt.figure()
plt.subplot(3,3,1)
plt.plot(x,y)
plt.title("Euler")

plt.subplot(3,3,2)
plt.plot(x2,y2)
plt.title("Leap-Frog")

plt.subplot(3,3,3)
plt.plot(x3,y3)
plt.title("Runge-Kutta")


plt.subplot(3,3,4)
plt.plot(x4,y4)
plt.title("Euler")

plt.subplot(3,3,5)
plt.plot(x5,y5)
plt.title("Leap-Frog")

plt.subplot(3,3,6)
plt.plot(x6,y6)
plt.title("Runge-Kutta")

plt.subplot(3,3,7)
plt.plot(x7,y7)
plt.title("Euler")

plt.subplot(3,3,8)
plt.plot(x8,y8)
plt.title("Leap-Frog")

plt.subplot(3,3,9)
plt.plot(x9,y9)
plt.title("Runge-Kutta")
plt.savefig("ORBITAS.png")
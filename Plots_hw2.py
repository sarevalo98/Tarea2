import numpy as np
import matplotlib.pylab as plt

datos=np.genfromtxt("Euler.dat",delimiter=" ")
T=datos[:,0]
x=datos[:,1]
y=datos[:,3]
vx=datos[:,2]
vy=datos[:,4]
mo=datos[:,5]
E=datos[:,6]

datos2=np.genfromtxt("LeapFrog.dat",delimiter=" ")
T2=datos2[:,0]
x2=datos2[:,1]
y2=datos2[:,3]
vx2=datos2[:,2]
vy2=datos2[:,4]
mo2=datos2[:,5]
E2=datos2[:,6]

datos3=np.genfromtxt("RungeKutta.dat",delimiter=" ")
T3=datos3[:,0]
x3=datos3[:,1]
y3=datos3[:,3]
vx3=datos3[:,2]
vy3=datos3[:,4]
mo3=datos3[:,5]
E3=datos3[:,6]

datos4=np.genfromtxt("Euler1.dat",delimiter=" ")
T4=datos4[:,0]
x4=datos4[:,1]
y4=datos4[:,3]
vx4=datos4[:,2]
vy4=datos4[:,4]
mo4=datos4[:,5]
E4=datos4[:,6]

datos5=np.genfromtxt("LeapFrog1.dat",delimiter=" ")
T5=datos5[:,0]
x5=datos5[:,1]
y5=datos5[:,3]
vx5=datos5[:,2]
vy5=datos5[:,4]
mo5=datos5[:,5]
E5=datos5[:,6]

datos6=np.genfromtxt("RungeKutta1.dat",delimiter=" ")
T6=datos6[:,0]
x6=datos6[:,1]
y6=datos6[:,3]
vx6=datos6[:,2]
vy6=datos6[:,4]
mo6=datos6[:,5]
E6=datos6[:,6]

datos7=np.genfromtxt("Euler2.dat",delimiter=" ")
T7=datos7[:,0]
x7=datos7[:,1]
y7=datos7[:,3]
vx7=datos7[:,2]
vy7=datos7[:,4]
mo7=datos7[:,5]
E7=datos7[:,6]

datos8=np.genfromtxt("LeapFrog2.dat",delimiter=" ")
T8=datos8[:,0]
x8=datos8[:,1]
y8=datos8[:,3]
vx8=datos8[:,2]
vy8=datos8[:,4]
mo8=datos8[:,5]
E8=datos8[:,6]

datos9=np.genfromtxt("RungeKutta2.dat",delimiter=" ")
T9=datos9[:,0]
x9=datos9[:,1]
y9=datos9[:,3]
vx9=datos9[:,2]
vy9=datos9[:,4]
mo9=datos9[:,5]
E9=datos9[:,6]

###Grafica de posiciones
plt.figure(figsize=(10,10))
plt.subplot(3,3,1)
plt.plot(x,y,label="h=0.01")
plt.legend()
plt.title("Euler")

plt.subplot(3,3,2)
plt.plot(x2,y2,label="h=0.01")
plt.legend()
plt.title("Leap-Frog")

plt.subplot(3,3,3)
plt.plot(x3,y3,label="h=0.01")
plt.legend()
plt.title("Runge-Kutta")


plt.subplot(3,3,4)
plt.plot(x4,y4,label="h=0.005")
plt.legend()
plt.title("Euler")

plt.subplot(3,3,5)
plt.plot(x5,y5,label="h=0.005")
plt.legend()
plt.title("Leap-Frog")

plt.subplot(3,3,6)
plt.plot(x6,y6,label="h=0.005")
plt.legend()
plt.title("Runge-Kutta")

plt.subplot(3,3,7)
plt.plot(x7,y7,label="h=0.001")
plt.legend()
plt.title("Euler")

plt.subplot(3,3,8)
plt.plot(x8,y8,label="h=0.001")
plt.legend()
plt.title("Leap-Frog")

plt.subplot(3,3,9)
plt.plot(x9,y9,label="h=0.001")
plt.legend()
plt.title("Runge-Kutta")
plt.savefig("ORBITAS.png")

##Grafica de velocidades
plt.figure(figsize=(10,10))
plt.subplot(3,3,1)
plt.plot(vx,vy,label="h=0.01")
plt.legend()
plt.title("Euler")

plt.subplot(3,3,2)
plt.plot(vx2,vy2,label="h=0.01")
plt.legend()
plt.title("Leap-Frog")

plt.subplot(3,3,3)
plt.plot(vx3,vy3,label="h=0.01")
plt.legend()
plt.title("Runge-Kutta")


plt.subplot(3,3,4)
plt.plot(vx4,vy4,label="h=0.005")
plt.legend()
plt.title("Euler")

plt.subplot(3,3,5)
plt.plot(vx5,vy5,label="h=0.005")
plt.legend()
plt.title("Leap-Frog")

plt.subplot(3,3,6)
plt.plot(vx6,vy6,label="h=0.005")
plt.legend()
plt.title("Runge-Kutta")

plt.subplot(3,3,7)
plt.plot(vx7,vy7,label="h=0.001")
plt.legend()
plt.title("Euler")

plt.subplot(3,3,8)
plt.plot(vx8,vy8,label="h=0.001")
plt.legend()
plt.title("Leap-Frog")

plt.subplot(3,3,9)
plt.plot(vx9,vy9,label="h=0.001")
plt.legend()
plt.title("Runge-Kutta")
plt.savefig("VELOCIDADES.png")

###Grafica de Momentum
plt.figure(figsize=(10,10))
plt.subplot(3,3,1)
plt.plot(T,mo,label="h=0.01")
plt.legend()
plt.title("Euler")

plt.subplot(3,3,2)
plt.plot(T2,mo2,label="h=0.01")
plt.legend()
plt.title("Leap-Frog")

plt.subplot(3,3,3)
plt.plot(T3,mo3,label="h=0.01")
plt.legend()
plt.title("Runge-Kutta")


plt.subplot(3,3,4)
plt.plot(T4,mo4,label="h=0.005")
plt.legend()
plt.title("Euler")

plt.subplot(3,3,5)
plt.plot(T5,mo5,label="h=0.005")
plt.legend()
plt.title("Leap-Frog")

plt.subplot(3,3,6)
plt.plot(T6,mo6,label="h=0.005")
plt.legend()
plt.title("Runge-Kutta")

plt.subplot(3,3,7)
plt.plot(T7,mo7,label="h=0.001")
plt.legend()
plt.title("Euler")

plt.subplot(3,3,8)
plt.plot(T8,mo8,label="h=0.001")
plt.legend()
plt.title("Leap-Frog")

plt.subplot(3,3,9)
plt.plot(T9,mo9,label="h=0.001")
plt.legend()
plt.title("Runge-Kutta")
plt.savefig("MOMENTUM_ANGULAR.png")

###Grafica de Energia
plt.figure(figsize=(10,10))
plt.subplot(3,3,1)
plt.plot(T,E,label="h=0.01")
plt.legend()
plt.title("Euler")

plt.subplot(3,3,2)
plt.plot(T2,E2,label="h=0.01")
plt.legend()
plt.title("Leap-Frog")

plt.subplot(3,3,3)
plt.plot(T3,E3,label="h=0.01")
plt.legend()
plt.title("Runge-Kutta")


plt.subplot(3,3,4)
plt.plot(T4,E4,label="h=0.005")
plt.legend()
plt.title("Euler")

plt.subplot(3,3,5)
plt.plot(T5,E5,label="h=0.005")
plt.legend()
plt.title("Leap-Frog")

plt.subplot(3,3,6)
plt.plot(T6,E6,label="h=0.005")
plt.legend()
plt.title("Runge-Kutta")

plt.subplot(3,3,7)
plt.plot(T7,E7,label="h=0.001")
plt.legend()
plt.title("Euler")

plt.subplot(3,3,8)
plt.plot(T8,E8,label="h=0.001")
plt.legend()
plt.title("Leap-Frog")

plt.subplot(3,3,9)
plt.plot(T9,E9,label="h=0.001")
plt.legend()
plt.title("Runge-Kutta")
plt.savefig("ENERGIA_SISTEMA.png")
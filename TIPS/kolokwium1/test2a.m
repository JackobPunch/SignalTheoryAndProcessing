t=linspace(0,2*pi,1000);
x0=0;
x1=2*(cos(t)+j*sin(t));
x2=-4j*(cos(2*t)+j*sin(2*t));
x3=6*(cos(3*t)+j*sin(3*t));
x4=-8j*(cos(4*t)+j*sin(4*t));

x=x0+x1+conj(x1)+x2+conj(x2)+x3+conj(x3)+x4+conj(x4);
var(x)
% Napisać skrypt generujący impuls prostokątny o czasie trwania N, przesunięciu c,
% szerokości b. Wielkości te wyrażone są liczbą próbek (przykładowo N=100, c=50, b=20).
N=100; 
c=50; 
b=20; 
x1=[zeros(1,c) ones(1,b) zeros(1,N-c-b)];  
figure
plot(x1,'.-r'); 

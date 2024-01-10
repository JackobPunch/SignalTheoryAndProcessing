clc
close all
clear all
f=333;
fp=880;
n=100;
% T=1/fp*n;
% t=linspace(0,T,n);
% t=[0:1/fp:T]; 
t=[0:n-1]*1/fp;
x=sin(2*pi*f*t);
var(x)
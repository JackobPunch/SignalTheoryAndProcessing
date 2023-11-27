clc
close all
clear all
f=333;
fp=880;
n=100;
T=1/fp*n;
t=linspace(1,T+1,n);
% t=[0:1/fp:T]; 
x=sin(2*pi*f*t);
var(x)
clear all;
clc;
Im1=imread('Im1.jpg');
Im2=imread('Im2.jpg');
ImF=imread('ImF.jpg');
F=VIFF_Public(Im1,Im2,ImF);
F

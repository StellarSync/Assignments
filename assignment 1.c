#include<stdio.h>

int main()

{

float km, m, cm, f, in;

printf("Enter distance in kilometers: ");

scanf("%f", &km);

m = km * 1000;

cm = km * 1000 * 100;

f = km * 3280.839895;

in = km * 39370;

printf("The distance in Meters: %f\n", m);

printf("The distance in Centimeters: %f\n", cm);

printf("The distance in Feet: %f\n", f);

printf("The distance in Inches: %f\n", in);

return (0);

}
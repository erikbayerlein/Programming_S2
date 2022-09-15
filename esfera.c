#include <stdio.h>
#define pi 3.14

float volume (float r);
float area (float r);

int main (void) {
    float r, vol, a;

    printf ("Digite o raio da esfera: ");
    scanf ("%f", &r);

    vol = volume (r);
    a = area (r);

    printf ("O volume e: %.2f\n", vol);
    printf ("A area e: %.2f", a);

    return 0;
}

float volume (float r) {
    float vol;

    vol = (4.0*pi*r*r*r)/3.0;

    return vol;
}

float area (float r) {
    float a;

    a = 4.0*pi*r*r;

    return a;
}
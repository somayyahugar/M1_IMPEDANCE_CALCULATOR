#include <stdio.h>
#include <complex.h>
#include <stdlib.h>

#define INFINITY 1e100
#define PI 3.14159265358979


typedef enum  type { Resistor, Capacitor, Inductor, Series, Parallel } Type;

typedef struct component {
  double value;
  Type type;
  unsigned int n;             // If parallel or serial
  struct component *nodes[];  // If parallel or serial
} Component;

Component *newcomponent(void) {
  char *names[] = { "Resistor", "Capacitor", "Inductor", "Series", "Parallel",
  NULL };
  Component *c = NULL;
  Type type;
  int n;

  while(1) {
    printf("What type of component?\n");
    for (int i = 0; names[i] != NULL; ++i)
      printf("%d\t%s\n", i, names[i]);

    scanf("%d", &type);
    switch(type) {
    case Resistor:
    case Capacitor:
    case Inductor:
      c = malloc(sizeof *c);
      c->type = type;
      while( 1 ) {
        printf("Please enter the value of the %s\n", names[c->type]);
        scanf("%lg", &c->value);
        if ( c->value > 0)
          return c;
        printf("Please enter a positive value\n");
      }

    case Series:
    case Parallel:
      while( 1 ) {
        printf("How many nodes are there?\n");
        scanf("%ud", &n);
        if ( n > 0)
          break;
        printf("Please enter a positive value\n");
      }

      c = malloc(sizeof *c + n * sizeof *c->nodes);
      c->n = n;
      for (n = 0; n < c->n; ++n)
        c->nodes[n] = newcomponent();
      return c;

    default:
      printf("Sorry \"%d\" is not a valid option, please try again\n",
             c->type);

    }
  }
}

double complex impedance(Component *c, double freq) {
  double complex z = 0;
  double denom;

  switch (c->type) {
  case Resistor:
    return c->value;

  case Inductor:
    return 2 * PI * I * c->value * freq;

  case Capacitor:
    // Handle DC and v low frequencies
    denom = 2 * PI * c->value * freq;
    if ( denom < 1.0/INFINITY )
     denom = 1.0/INFINITY;
    return 1.0/(I * denom);

  case Series:
    for (int n = 0; n < c->n; ++n)
      z += impedance(c->nodes[n], freq);
    return z;

  case Parallel:
    for (int n = 0; n < c->n; ++n)
      z += 1.0/impedance(c->nodes[n], freq);
    return 1.0/z;
  }
}

int main() {
  Component *c = NULL;
  double complex z;

  c = newcomponent();
  z = impedance(c, 50000);
  printf("The impedance is:\n"
         "\tmodulus %g and phase %g\n",
         cabs(z), carg(z));

  return 0;
}

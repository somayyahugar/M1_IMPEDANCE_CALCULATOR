/**
 * @file Impedance_calculator.h
 * @author Somayya N Hugar
 * @Find the impedance of an electrical circuit.
 *
 */

#include <stdio.h>
#include <complex.h>
#include <stdlib.h>
#define INFINITY 1e100
#define PI 3.14159265358979

/**
*In this part we will define what type of component is present in the circuit.
*/
typedef enum  type { Resistor, Capacitor, Inductor, Series, Parallel } Type;


/**
*The following code will read in a single component:

*/
char *names[] = { "Resistor", "Capacitor", "Inductor"};

/**
*We can allow for multiple coponents ina circuit by adding an extra option to the switch() statement that allocates an array of circuit pointers and recursively calls newcomponent() to fill it.

*We will have to choose how many nodes present in the circuit as well as series circuit or parallel circuit.
*/

 case Series:
    case Parallel:
    
/**
*here we will calculate the 
*/
double complex impedance(Component *c, double freq)
 

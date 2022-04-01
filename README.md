# M1_IMPEDANCE_CALCULATOR
  Impedance between two points in an electronic circuit can be defined as the ratio of the voltage difference and the current. It is the AC voltage difference between the two points divided by the AC current. It is assumed here that the AC voltage and currents are sinusoidal with a frequency ‘f’ cycles/sec (the radian frequency, ω, equals 2πf radians/sec). In general, impedance is a function of frequency. The unit of impedance is Ohms (Ohm= volt/ampere).
	Impedances can be combined in series and parallel in the same manner as resistors.
	
**Algorithm**
1)Include the Header file 
2)Make a Structure to choose the components as series or parallel connected network.
3)After that read in a single component from Capacitor,Resistor,Inductor.
4)We can allow for multiple coponents ina circuit by adding an extra option to the switch() statement that allocates an array of circuit pointers and recursively calls newcomponent() to fill it.
5)Then calculate the impedance of the component by using it's mathematical expression.
*For a pure resistor of resistance R Ohms, the impedance ZR = R Ohms.
*For a pure inductor of inductance L Henries, the impedance ZL= jωL Ohms.
*For a pure capacitor of capacitance C Farads, the impedance ZC = 1/jωC Ohms.
6)Return with its impedance value.


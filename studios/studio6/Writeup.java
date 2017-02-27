package studio6;

public class Writeup {

	/*
	 * 2.1 Number bases
	 * 
	 * 01011010 = 0x5a
	 * 1111111100111100 = 0xff3c
	 * 01100111 = 0x67
	 * 
	 * 0xfe = 11111110
	 * 0x4321 = 0100001100100001
	 * 0x20 = 00100000
	 * 
	 * 0x132 = 306
	 * 0xcd = 205
	 * 0x11 = 17
	 * 
	 * 723 = 0x2d3
	 * 100 = 0x64
	 * 50 = 0x32
	 * 
	 * 2.2 Integer and fixed-point representations
	 * 
	 * -1 = 11111111(two's complement), 10000001(sign-magnitude), 01111110(excess-127)
	 * -2 = 11111110, 10000010, 01111101
	 * Most significant bit = -(2^7)
	 * Least significant bit = 2^0 = 1
	 * Q1.15 has 15 fractional bits
	 * 
	 * 2.3 Floating point representation
	 * - exponent of a float has 8 bits
	 * - double in C/Java has 4/8 bytes
	 * - As a whole (sign-magnitude) / exponent (excess-127)
	 * 
	 * 2.4 Strings - Strings.ino
	 * 
	 * 3 C language - Clanguage.ino
	 * 
	 * 4 Timing
	 * - When using delay(), we halt the operation for the designated amount of time,
	 * but then it takes some other time to perform other parts of the program.
	 * - Setting wrong intervals, or running the program for more than 49/50 days
	 * 
	 * 5 Analog inputs
	 * 
	 * 6 Digital outputs
	 * - Anode(+) has higher voltage than cathode(-)
	 * - Resistor between 200~500Ohms
	 * - Orientation of the resistor does not matter
	 * - Wire resistor first, but location between the two does not matter
	 * - Red-red-brown-gold = 220 +- 5% / yellow-orange-red-gold = 4300 +- 5%
	 * 
	 * 7 Digital inputs - Digitalinputs.ino 
	 * 
	 * 8 FSMs - FSMs.ino / FSMs.java
	 * 
	 * 9 Streams and communication
	 * - available(), readByte(), writeByte()
	 * - (0x21): beginning anchor of message, ignore bytes until magic number is received
	 */
	
}

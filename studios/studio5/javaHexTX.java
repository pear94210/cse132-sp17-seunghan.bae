package studio5;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import jssc.SerialPortException;
import studio4.SerialComm;

public class javaHexTX {

	public static void main(String[] args) throws IOException, SerialPortException {
		
		SerialComm port = new SerialComm("COM3");
		
		while(true) {
			System.out.println("Input:");
			
			BufferedReader sys = new BufferedReader(new InputStreamReader(System.in));
			int input = (int)sys.read();
			if (input >= 48  && input <= 57) input -= 48;
			else if (input >= 65 && input <= 70) input -= 55;
			else if (input >= 97 && input <= 102) input -= 87;
			else input = -1;
			
			if (input >= 0 && input <= 15) System.out.print(input);
			else System.out.println("INVALID INPUT");
			
			port.writeByte((byte)input);
		}
		
	}
	
}

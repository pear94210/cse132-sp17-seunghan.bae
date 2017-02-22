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
			System.out.println("Enter input:");
			
			BufferedReader sys = new BufferedReader(new InputStreamReader(System.in));
			byte input = (byte)sys.read();
			if (input >= 0x30  && input <= 0x39) input -= 0x30;
			else if (input >= 0x41 && input <= 0x46) input -= 0x37;
			else if (input >= 0x61 && input <= 0x66) input -= 0x57;
			else input = -1;
			
			if (input >= 0 && input <= 15) System.out.print(input);
			else System.out.print("INVALID INPUT");
			
			port.writeByte((byte)input);
			System.out.println();
		}
		
	}
	
}

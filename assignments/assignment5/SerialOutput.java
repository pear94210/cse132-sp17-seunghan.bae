package assignment5;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import jssc.SerialPortException;
import studio4.SerialComm;

public class SerialOutput {
	
	public static void main(String[] args) throws SerialPortException, IOException {
		
		SerialComm port = new SerialComm("COM3");
		
		while (true) {
			System.out.println("Enter input:");
			
			BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
			String input = in.readLine();
			
			System.out.print(input);
			
			for (int i = 0; i < input.length(); i++) {
				port.writeByte((byte)input.charAt(i));
			}
			System.out.println();
		}
		
	}
	
}

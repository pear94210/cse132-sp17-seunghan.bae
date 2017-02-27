package studio6;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

import jssc.SerialPortException;
import studio4.SerialComm;

public class FSMs {

	public static void main(String[] args) throws SerialPortException, IOException {
		
//		SerialComm port = new SerialComm("COM3");
		while (true) {
			System.out.println("Enter Input: ");
			
			BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
			String s = in.readLine();
			
			System.out.print(s + ": ");
			if (s.charAt(0) == 's' && s.charAt(1) == 't') System.out.print(1);
			for (int i = 0; i < s.length(); i++) {
				if (s.charAt(i) == ' ' && s.charAt(i + 1) == 's' && s.charAt(i + 2) == 't') System.out.print(1);
			}
			
			System.out.println();
		}
		
	}

}

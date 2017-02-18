package assignment4;

import jssc.SerialPortException;
import studio4.SerialComm;

public class MsgReceiver {
	
	final private SerialComm port;
	
	public MsgReceiver(String portname) throws SerialPortException {
		port = new SerialComm(portname);
	}

	public void run() throws SerialPortException {
		// insert FSM code here to read msgs from port
		// and write to console
		while (true) {
			if (port.available()) {
				if (port.readByte() == 0x21) {
					byte byteType = port.readByte();
					
					if (byteType == 0x30) {
						System.out.print("Debug String: ");
						int[] input = new int[2];
						for (int i = 0; i < input.length; i++) {
							input[i] = port.readByte();
							if (input[i] < 0) input[i] += 256;
						}
						
						int stringLength = (input[0] << 8) | input[1];
						String byteString = "";
						for (int i = 0; i < stringLength; i++) {
							byte c = port.readByte();
							if (c >= 0x01 && c <= 0x7f) {
								byteString = byteString + (char)c;
							} else System.out.println("WRONG CHARACTER");
						}
						
						System.out.println(byteString);
					} else if (byteType == 0x32) {
						System.out.print("Timestamp: ");
						int[] input = new int[4];
						for (int i = 0; i < input.length; i++) {
							input[i] = port.readByte();
							if (input[i] < 0) input[i] += 256;
						}
						
						int byteInt = (input[0] << 24) | (input[1] << 16) | (input[2] << 8) | input[3];
						System.out.println(byteInt);
					} else if (byteType == 0x33) {
						System.out.print("Potentiometer Reading: ");
						int[] input = new int[2];
						for (int i = 0; i < input.length; i++) {
							input[i] = port.readByte();
							if (input[i] < 0) input[i] += 256;
						}
						
						int byteShort = (input[0] << 8) | input[1];
						System.out.println(byteShort);
					} else if (byteType == 0x34) {
						System.out.print("Raw Temperature Reading: ");
						int[] input = new int[2];
						for (int i = 0; i < input.length; i++) {
							input[i] = port.readByte();
							if (input[i] < 0) input[i] += 256;
						}
						
						int byteShort = (input[0] << 8) | input[1];
						System.out.println(byteShort);
					} else if (byteType == 0x35) {
						System.out.print("Unfiltered Temperature Reading: ");
						int[] input = new int[4];
						for (int i = 0; i < input.length; i++) {
							input[i] = port.readByte();
							if (input[i] < 0) input[i] += 256;
						}
						
						int byteFloat = (input[0] << 24) | (input[1] << 16) | (input[2] << 8) | input[3];
						//System.out.println(String.format("%02x", byteFloat));
						float byteTemp = Float.intBitsToFloat(byteFloat);
						System.out.println(byteTemp);
					} else if (byteType == 0x36) {
						System.out.print("Filtered Temperature Reading: ");
						int[] input = new int[4];
						for (int i = 0; i < input.length; i++) {
							input[i] = port.readByte();
							if (input[i] < 0) input[i] += 256;
						}
						
						int byteFloat = (input[0] << 24) | (input[1] << 16) | (input[2] << 8) | input[3];
						//System.out.println(String.format("%02x", byteFloat));
						float byteTemp = Float.intBitsToFloat(byteFloat);
						System.out.println(byteTemp);
					} else System.out.println("WRONG FORMAT OF DATA");
				} else System.out.println("MESSAGE MUST START WITH '!'");
			}
		}
	}

	public static void main(String[] args) throws SerialPortException {
		MsgReceiver msgr = new MsgReceiver("COM3"); // Adjust this to be the right port for your machine
		msgr.run();
	}
}

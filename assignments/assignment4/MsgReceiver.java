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
						System.out.print("Debug String");
						int byte1 = port.readByte();
						int byte2 = port.readByte();
						if (byte2 < 0) byte2 += 256;
						int stringLength = (byte1 << 8) | byte2;
						
						String byteString = "";
						for (int i = 0; i < stringLength; i++) {
							byte c = port.readByte();
							if (c >= 0x01 && c <= 0x7f) {
								byteString = byteString + (char)c;
							} else System.out.println("WRONG CHARACTER");
						}
						
						System.out.println(byteString);
					} else if (byteType == 0x32) {
						System.out.print("4-byte Integer");
						int longLength = port.readByte();
						if (longLength == 4) {
							int byteInt = 0;
							for (int i = 0; i < longLength; i++) {
								int n = port.readByte();
								if (n < 0) n += 256;
								byteInt = (byteInt << 8) | n;
							}
							
							System.out.println(byteInt);
						} else System.out.println("CAN ONLY SEND 4 BYTES");

					} else if (byteType == 0x33) {
						System.out.print("Potentiometer Reading");
						int intLength = port.readByte();
						if (intLength == 2) {
							int byteInt = 0;
							for (int i = 0; i < intLength; i++) {
								int n = port.readByte();
								if (n < 0) n += 256;
								byteInt = (byteInt << 8) | n;
							}
							
							System.out.println(byteInt);
						} else System.out.println("CAN ONLY SEND 2 BYTES");
						
					} else if (byteType == 0x34) {
						System.out.print("Raw Temperature Reading");
						int intLength = port.readByte();
						if (intLength == 2) {
							int byteInt = 0;
							for (int i = 0; i < intLength; i++) {
								int n = port.readByte();
								if (n < 0) n += 256;
								byteInt = (byteInt << 8) | n;
							}
							
							System.out.println(byteInt);
						} else System.out.println("CAN ONLY SEND 2 BYTES");
						
					} else if (byteType == 0x35) {
						System.out.print("Unfiltered Temperature Reading");
						int tempLength = port.readByte();
						if (tempLength == 4) {
							int byteTemp = 0;
							for (int i = 0; i < tempLength; i++) {
								int n = port.readByte();
								if (n < 0) n += 256;
								byteTemp = (byteTemp << 8) | n;
							}
							
							int s = ((byteTemp >> 31) == 0) ? 1 : -1;
							int e = ((byteTemp >> 23) & 0xff);
							int m = (e == 0) ? (byteTemp & 0x7fffff) << 1 : (byteTemp & 0x7fffff) | 0x800000;
							
							System.out.println((float)s * m * Math.pow(2, e - 150));
						} else System.out.println("CAN ONLY SEND 4 BYTES");
						
					} else if (byteType == 0x36) {
						System.out.print("Filtered Temperature Reading");
						int tempLength = port.readByte();
						if (tempLength == 4) {
							int byteTemp = 0;
							for (int i = 0; i < tempLength; i++) {
								int n = port.readByte();
								if (n < 0) n += 256;
								byteTemp = (byteTemp << 8) | n;
							}
							
							int s = ((byteTemp >> 31) == 0) ? 1 : -1;
							int e = ((byteTemp >> 23) & 0xff);
							int m = (e == 0) ? (byteTemp & 0x7fffff) << 1 : (byteTemp & 0x7fffff) | 0x800000;
							
							System.out.println((float)s * m * Math.pow(2, e - 150));
						} else System.out.println("CAN ONLY SEND 4 BYTES");
						
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

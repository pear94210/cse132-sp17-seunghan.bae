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
			if (port.available() && port.readByte() == 0x21) {
				if (port.readByte() == 0x30) {
					int byte1 = port.readByte();
					int byte2 = port.readByte();
					if (byte2 < 0) byte2 += 256;
					int stringLength = (byte1 << 8) | byte2;
					
					for (int i = 0; i < stringLength; i++) {
						System.out.print((char)port.readByte());
					}
					System.out.println();
				}
			}
		}
	}

	public static void main(String[] args) throws SerialPortException {
		MsgReceiver msgr = new MsgReceiver("COM3"); // Adjust this to be the right port for your machine
		msgr.run();
	}
}

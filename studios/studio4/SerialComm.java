package studio4;

import jssc.SerialPort;
import jssc.SerialPortException;

public class SerialComm {

	SerialPort port;
	boolean debug = true;
	
	public SerialComm(String name) throws SerialPortException {
		port = new SerialPort(name);
		port.openPort();
		port.setParams(SerialPort.BAUDRATE_9600, 
				SerialPort.DATABITS_8, 
				SerialPort.STOPBITS_1, 
				SerialPort.PARITY_NONE);
	}
	
	public boolean available() throws SerialPortException {
		return port.getInputBufferBytesCount() != 0;
	}
	
	public byte readByte() throws SerialPortException {
		byte[] byteArray = port.readBytes(1);
		
		if (debug) {
			System.out.print("[0x" + String.format("%02x", byteArray[0]) + "]");
		}
		
		return byteArray[0];
	}
	
	public static void main(String[] args) throws SerialPortException {
		SerialComm comm = new SerialComm("COM3");
		
		while (true) {
			if (comm.available()) {
				int byte1 = comm.readByte();
				int byte2 = comm.readByte();
				if (byte2 < 0) byte2 += 256;
				System.out.println((byte1 << 8) | byte2);
			}
			
		}
	}
	
}

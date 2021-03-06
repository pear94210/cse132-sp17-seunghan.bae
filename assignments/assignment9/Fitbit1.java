package assignment9;

import java.nio.charset.StandardCharsets;

import jssc.SerialPortException;
import studio4.SerialComm;

public class Fitbit1 {

	final private SerialComm port;
	
	public Fitbit1(String portname) throws SerialPortException {
		port = new SerialComm(portname);
	}
	
	public void run() throws SerialPortException {
		while (true) {
			if (port.available()) {
				if (port.readByte() == 0x23) {
					byte byteType = port.readByte();
					
					switch (byteType) {
					case 0x30:
						System.out.print("Debug String: ");
						int[] input30 = new int[2];
						for (int i = 0; i < input30.length; i++) {
							input30[i] = port.readByte();
							if (input30[i] < 0) input30[i] += 256;
						}
						int stringLength = (input30[0] << 8) | input30[1];
						
						byte[] byte30 = new byte[stringLength];
						for (int i = 0; i < byte30.length; i++) {
							byte30[i] = port.readByte();
						}
						String byte30String = new String(byte30, StandardCharsets.UTF_8);
						
						System.out.println(byte30String);
						break;
						
					case 0x31:
						System.out.print("Error String: ");
						int[] input31 = new int[2];
						for (int i = 0; i < input31.length; i++) {
							input31[i] = port.readByte();
							if (input31[i] < 0) input31[i] += 256;
						}
						int errorLength = (input31[0] << 8) | input31[1];
						
						byte[] byte31 = new byte[errorLength];
						for (int i = 0; i < byte31.length; i++) {
							byte31[i] = port.readByte();
						}
						String byte31String = new String(byte31, StandardCharsets.UTF_8);
						
						System.out.println(byte31String);
						break;
						
					case 0x32:
						System.out.print("Step Counts: ");
						int[] input32 = new int[4];
						for (int i = 0; i < input32.length; i++) {
							input32[i] = port.readByte();
							if (input32[i] < 0) input32[i] += 256;
						}
						int byte32 = (input32[0] << 24) | (input32[1] << 16) | (input32[2] << 8) | input32[3];
						
						System.out.println(byte32);
						break;

					case 0x33:
						System.out.print("Sleep Time: ");
						int[] input33 = new int[4];
						for (int i = 0; i < input33.length; i++) {
							input33[i] = port.readByte();
							if (input33[i] < 0) input33[i] += 256;
						}
						int byte33 = (input33[0] << 24) | (input33[1] << 16) | (input33[2] << 8) | input33[3];
					
						System.out.println(byte33);
						break;

					case 0x34:
						System.out.print("Temperature: ");
						int[] input34 = new int[4];
						for (int i = 0; i < input34.length; i++) {
							input34[i] = port.readByte();
							if (input34[i] < 0) input34[i] += 256;
						}
						int byte34 = (input34[0] << 24) | (input34[1] << 16) | (input34[2] << 8) | input34[3];
						float byte34Float = Float.intBitsToFloat(byte34);
						
						System.out.println(byte34Float);
						break;
						
					case 0x35:
						System.out.print("Total Runtime: ");
						int[] input35 = new int[4];
						for (int i = 0; i < input35.length; i++) {
							input35[i] = port.readByte();
							if (input35[i] < 0) input35[i] += 256;
						}
						int byte35 = (input35[0] << 24) | (input35[1] << 16) | (input35[2] << 8) | input35[3];
						
						System.out.println(byte35);
						break;

					default:
						System.out.println("UNDEFINED DATA TYPE");
						break;
					}
				} else System.out.println("MESSAGE MUST START WITH #(0x23)");
			}
		}
	}

	public static void main(String[] args) throws SerialPortException {
		Fitbit1 fitbit = new Fitbit1("COM3");
		fitbit.run();
	}

}

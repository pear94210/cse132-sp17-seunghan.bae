package assignment10;

import java.awt.Color;
import java.nio.charset.StandardCharsets;

import jssc.SerialPortException;
import sedgewick.StdDraw;
import studio4.SerialComm;

public class Fitbit2 {

	final private SerialComm port;
	
	public Fitbit2(String portname) throws SerialPortException {
		port = new SerialComm(portname);
	}
	
	public static void main(String[] args) throws SerialPortException {
		//drawGraph();
		
		Fitbit2 fitbit = new Fitbit2("/dev/cu.usbserial-DN02B7PZ");
		fitbit.run();
	}
	
	public void run() throws SerialPortException {
		int[] index = new int[45];
		for (int i = 0; i < index.length; i++) index[i] = i;
		double[] accel = new double[45];
		int[] sleep = new int[45];
		
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
						//System.out.print("Step Counts: ");
						int[] input32 = new int[4];
						for (int i = 0; i < input32.length; i++) {
							input32[i] = port.readByte();
							if (input32[i] < 0) input32[i] += 256;
						}
						int byte32 = (input32[0] << 24) | (input32[1] << 16) | (input32[2] << 8) | input32[3];
						
						String stepCount = "You walked " + byte32 + " steps";
						StdDraw.textLeft(0, -1, stepCount);
						
						StdDraw.show();
						
						//System.out.println(byte32);
						break;

					case 0x33:
						//System.out.print("Sleep Time: ");
						int[] input33 = new int[4];
						for (int i = 0; i < input33.length; i++) {
							input33[i] = port.readByte();
							if (input33[i] < 0) input33[i] += 256;
						}
						int byte33 = (input33[0] << 24) | (input33[1] << 16) | (input33[2] << 8) | input33[3];
						
						for (int i1 = 0; i1 < accel.length; i1++) accel[i1] = 0;
						for (int i2 = 0; i2 < sleep.length - 1; i2++) sleep[i2] = sleep[i2 + 1];
						sleep[sleep.length - 1] = byte33;
						
						StdDraw.clear();
						drawGraph();
						drawSleep();
						
						StdDraw.setPenColor(Color.BLUE);
						StdDraw.setPenRadius(StdDraw.getPenRadius() * 2);
						for (int i3 = 0; i3 < index.length - 1; i3++) StdDraw.line(index[i3], sleep[i3] / 20000.0, index[i3 + 1], sleep[i3 + 1] / 20000.0);
						StdDraw.setPenRadius(StdDraw.getPenRadius() / 2);
						StdDraw.setPenColor(Color.BLACK);
						
						String sleepTime = "You slept for " + byte33 + "ms";
						StdDraw.textLeft(0, -1, sleepTime);
						
						StdDraw.show();
					
						//System.out.println(byte33);
						break;

					case 0x34:
						//System.out.print("Temperature: ");
						int[] input34 = new int[4];
						for (int i = 0; i < input34.length; i++) {
							input34[i] = port.readByte();
							if (input34[i] < 0) input34[i] += 256;
						}
						int byte34 = (input34[0] << 24) | (input34[1] << 16) | (input34[2] << 8) | input34[3];
						float byte34Float = Float.intBitsToFloat(byte34);
						
						String temperature = "It's " + byte34Float + " degrees.";
						StdDraw.textLeft(0, -2, temperature);
						
						StdDraw.show();
						
						//System.out.println(byte34Float);
						break;
						
					case 0x35:
						//System.out.print("Total Runtime: ");
						int[] input35 = new int[4];
						for (int i = 0; i < input35.length; i++) {
							input35[i] = port.readByte();
							if (input35[i] < 0) input35[i] += 256;
						}
						int byte35 = (input35[0] << 24) | (input35[1] << 16) | (input35[2] << 8) | input35[3];
						
						//System.out.println(byte35);
						break;
					
					case 0x36:
						//System.out.print("Raw Accelerometer Value (z): ");
						int[] input36 = new int[4];
						for (int i = 0; i < input36.length; i++) {
							input36[i] = port.readByte();
							if (input36[i] < 0) input36[i] += 256;
						}
						int byte36 = (input36[0] << 24) | (input36[1] << 16) | (input36[2] << 8) | input36[3];
						float byte36Float = Float.intBitsToFloat(byte36);
						
						for (int i1 = 0; i1 < sleep.length; i1++) sleep[i1] = 0;
						for (int i2 = 0; i2 < accel.length - 1; i2++) accel[i2] = accel[i2 + 1];
						accel[accel.length - 1] = byte36Float;
						
						StdDraw.clear();
						drawGraph();
						drawStep();
						
						StdDraw.setPenColor(Color.RED);
						StdDraw.setPenRadius(StdDraw.getPenRadius() * 5);
						for (int i3 = 0; i3 < index.length; i3++) StdDraw.point(index[i3], accel[i3]);
						StdDraw.setPenRadius(StdDraw.getPenRadius() / 5);
						StdDraw.setPenColor(Color.BLACK);
						
						//StdDraw.show();
						
						//System.out.println(byte36Float);
						break;
						
					case 0x37: 
						int[] input37 = new int[4];
						for (int i = 0; i < input37.length; i++) {
							input37[i] = port.readByte();
							if (input37[i] < 0) input37[i] += 256;
						}
						int byte37 = (input37[0] << 24) | (input37[1] << 16) | (input37[2] << 8) | input37[3];
						float byte37Float = Float.intBitsToFloat(byte37);
						
						String speed = "(" + byte37Float + " steps/hr)";
						StdDraw.textLeft(0, -1.5, speed);
						
						StdDraw.show();

					default:
						System.out.println("UNDEFINED DATA TYPE");
						break;
					}
				} else System.out.println("MESSAGE MUST START WITH #(0x23)");
			}
		}
	}
	
	public static void drawGraph() {
		StdDraw.enableDoubleBuffering();
		StdDraw.setXscale(-5, 50);
		StdDraw.setYscale(-3, 3);
		
		java.awt.Font font = StdDraw.getFont();
		
		StdDraw.setFont(new java.awt.Font(font.getName(), font.getStyle(), font.getSize() * 2));
		StdDraw.text(22.5, 2.5, "FITBIT");
		StdDraw.setFont(font);
		
		StdDraw.setPenRadius(StdDraw.getPenRadius() * 2);
		StdDraw.line(0, 0, 45, 0);
		StdDraw.line(0, 0, 0, 2);
		StdDraw.setPenRadius(StdDraw.getPenRadius() / 2);
		
		for (int i = 10; i <= 40; i += 10) {
			StdDraw.text(i, -0.25, String.valueOf(i));
			StdDraw.line(i, 0, i, 2);
		}
		StdDraw.textRight(-1, -0.25, "0");
		
		//StdDraw.show();
	}
	
	public static void drawStep() {
		for (double d = 0.5; d <= 1.5; d += 0.5) {
			StdDraw.textRight(-1, d, String.valueOf(d));
			StdDraw.line(0, d, 45, d);
		}
	}
	
	public static void drawSleep() {
		for (double d = 0.5; d <= 1.5; d += 0.5) {
			StdDraw.textRight(-1, d, String.valueOf((int)(d * 20)));
			StdDraw.line(0, d, 45, d);
		}
	}

}

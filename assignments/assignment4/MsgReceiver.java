package assignment4;

import jssc.SerialPortException;
import studio4.SerialComm;

public class MsgReceiver {
	
	final private SerialComm port;
	
	public MsgReceiver(String portname) {
		port = new SerialComm(portname);
	}

	public void run() {
		// insert FSM code here to read msgs from port
		// and write to console


	}

	public static void main(String[] args) {
		MsgReceiver msgr = new MsgReceiver("COM4"); // Adjust this to be the right port for your machine
		msgr.run();
	}
}

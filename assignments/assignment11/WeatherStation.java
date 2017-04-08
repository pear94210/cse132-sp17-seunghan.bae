package assignment11;

import java.io.InputStream;
import java.io.DataInputStream;
import java.net.HttpURLConnection;
import java.net.URL;

import jssc.SerialPortException;
import studio4.SerialComm;

public class WeatherStation {
	
	private static SerialComm port;
	
	public WeatherStation(String portname) throws SerialPortException {
		port = new SerialComm(portname);
	} 

    public static void main(String[] args) throws Exception {
        // Create a new instance of Weather Station
    	WeatherStation ws = new WeatherStation("/dev/cu.usbserial-DN02B7PZ");

        // Based on the name of the instance created above, call xx.sendGet().
        // This will test to the function we'll be creating below.
    	while (true) {
    		if (port.available()) {
        		if (port.readByte() == 0x21) {
        			int[] xArray = new int[4];
    				for (int i = 0; i < xArray.length; i++) {
    					xArray[i] = port.readByte();
    					if (xArray[i] < 0) xArray[i] += 256;
    				}
    				
    				int[] yArray = new int[4];
    				for (int i = 0; i < yArray.length; i++) {
    					yArray[i] = port.readByte();
    					if (yArray[i] < 0) yArray[i] += 256;
    				}
    				
    				int byteX = (xArray[0] << 24) | (xArray[1] << 16) | (xArray[2] << 8) | xArray[3];
    				float x = Float.intBitsToFloat(byteX);
    				int byteY = (yArray[0] << 24) | (yArray[1] << 16) | (yArray[2] << 8) | yArray[3];
    				float y = Float.intBitsToFloat(byteY);
    				System.out.println();
    				System.out.println(x);
    				System.out.println(y);
    				ws.sendGet(x, y);
        		}
        	}
    	}

    }

    // HTTP GET request
    private void sendGet(float x, float y) throws Exception {

        // Create a string that contains the URL you created for Lopata Hall in Studio 10
        // Use the URL that DOES NOT have the timestamp included.
        // Since we only need the current data (currently) you can use the API to exclude all of the excess blocks (REQUIRED).
        // Instructions to do that are here: https://darksky.net/dev/docs/forecast
        // Test this new URL by pasting it in your web browser. You should only see the information about the current weather.
    	String url1 = "https://api.darksky.net/forecast/c26405c49c44bb1af74e820709f12ee7/";
    	String url2 = String.valueOf(x);
    	String url3 = String.valueOf(y);
    	String url4 = "?exclude=minutely,hourly,daily,alerts,flags";
    	
    	String urlString = url1 + url2 + "," + url3 + url4;

        // Create a new URL object with the URL string you defined above. Reference: https://docs.oracle.com/javase/7/docs/api/java/net/URL.html
    	URL url = new URL(urlString);

        // Follow the instructions in the URL API to open this connection.
        // Cast this to a HttpURLConnection and save it in a new HttpURLConnection object.
    	HttpURLConnection huc = (HttpURLConnection)url.openConnection();

        // Use the HttpURLConnection API to setup the HttpURLConnection you defined above.
        // Reference: https://docs.oracle.com/javase/7/docs/api/java/net/HttpURLConnection.html
        // Set the request method.
    	huc.setRequestMethod("GET");

        // Set the request property "User-Agent" to the User-Agent you saw in Wireshark when you did the first exercise in studio.
        // Repeat the quick wireshark example if you've forgotten. It should be in the form "xxxxxxx/#.#"
    	huc.setRequestProperty("User-Agent", "Mozilla/5.0 (Macintosh; Intel Mac OS X 10_12_4) AppleWebKit/603.1.30 (KHTML, like Gecko) Version/10.1 Safari/603.1.30");

        // To debug, get and print out the response code.
    	System.out.println(huc.getResponseCode() + " " + huc.getResponseMessage());

        // The rest of the code should be much more familiar.
        // Create an InputStream that gets the input stream from our HttpURLConnection object.
    	InputStream in = huc.getInputStream();

        // Wrap it in a DataInputStream
    	DataInputStream dataIn = new DataInputStream(in);

        // Read a line and save it in a string
    	String s = dataIn.readLine();

        // Close the InputStream
    	in.close();

        // Using string manipulation tools, pull out the string between quotes after "icon:"
        // For example: "summary":"Clear","icon":"clear-day","nearestStormDistance":27
        // You should pull out JUST "clear-day"
    	String[] split = s.split(",");
    	String sub = split[6].substring(8, split[6].length() - 1);

        // You will set this char (in a switch statement) to one of the 5 types of weather. (Nothing TODO here)
        char weatherChar = '\0';

        // Create a switch statement based on the string that contains the description (ex. clear-day)
        // The switch statement should be able to handle all 10 of the icon values from the API: https://darksky.net/dev/docs/response
        // If the value is any of the cloudy ones, set weatherChar to C
        // If the value is fog, set it to F
        // If the value if wind, set it to W
        // If the value is any of the clear ones, set it to S
        // If the value is any type of precipitation, set it to P
        if (sub.equals("cloudy") || sub.equals("partly-cloudy-day") || sub.equals("partly-cloudy-night")) weatherChar = 'C';
        else if (sub.equals("fog")) weatherChar = 'F';
        else if (sub.equals("wind")) weatherChar = 'W';
        else if (sub.equals("clear-day") || sub.equals("clear-night")) weatherChar = 'S';
        else weatherChar = 'P';

        // Now you're ready to implement this into your past code to send it to the Arduino.
        // You also have to make a couple modifications to handle the switch location requests from Arduino.
        // Choose three locations or more, but make sure one is Lopata Hall.
        System.out.println(weatherChar);
        port.writeByte((byte)0x21);
        port.writeByte((byte)weatherChar);
        System.out.println();
    }
}
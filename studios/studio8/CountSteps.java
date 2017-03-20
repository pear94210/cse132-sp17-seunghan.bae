package studio8;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class CountSteps {

	public static void main(String[] args) throws FileNotFoundException {
		int count = 0;
		double[] compare = {0, 0, 0};
		
		String directory = "C:/Users/Seunghan/git/cse132-sp17-seunghan.bae/studios/studio8/data/data.csv";
		Scanner sc = new Scanner(new File(directory));
		
		while (sc.hasNext()) {
			String data = sc.next();
			String[] xyz = data.split(",");
			double x = Double.parseDouble(xyz[0]);
			double y = Double.parseDouble(xyz[1]);
			double z = Double.parseDouble(xyz[2]);
			
			compare[0] = compare[1];
			compare[1] = compare[2];
			compare[2] = z;
			
			if ((compare[1] > compare[0]) && (compare[1] > compare[2]) && (compare[1] > 1)) count++;
		}
		
		System.out.println(count);
	}
	
}

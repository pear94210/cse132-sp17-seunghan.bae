package studio10;

import java.awt.Color;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

import javafx.scene.text.Font;
import sedgewick.StdDraw;

public class Plot {

	public static void main(String[] args) throws FileNotFoundException {
		
		createChart();
		
		String directory = "C:/Users/Seunghan/git/cse132-sp17-seunghan.bae/studios/studio9/data/data.csv";
		Scanner sc = new Scanner(new File(directory));
		
		int time = 0;
		StdDraw.setPenRadius(0.005);
		
		while (sc.hasNext()) {
			String data = sc.next();
			String[] xyz = data.split(",");
			double x = Double.parseDouble(xyz[0]);
			double y = Double.parseDouble(xyz[1]);
			double z = Double.parseDouble(xyz[2]);
			time++;
			
			StdDraw.setPenColor(Color.BLACK);
			StdDraw.point(time, x);
			StdDraw.setPenColor(Color.RED);
			StdDraw.point(time, y);
			StdDraw.setPenColor(Color.BLUE);
			StdDraw.point(time, z);
		}

	}
	
	public static void createChart() {
		
		StdDraw.setXscale(-100, 700);
		StdDraw.setYscale(-1.5, 2.5);
		
		StdDraw.setPenRadius(StdDraw.getPenRadius() * 2);
		StdDraw.line(0, -1, 0, 2);
		StdDraw.line(0, 0, 650, 0);
		
		java.awt.Font font = StdDraw.getFont();
		
		StdDraw.setFont(new java.awt.Font(font.getName(), font.getStyle(), font.getSize() * 2));
		StdDraw.text(300, 2.25, "Accelerometer Graph");
		
		StdDraw.setFont(new java.awt.Font(font.getName(), java.awt.Font.BOLD, font.getSize()));
		StdDraw.text(-60, 0.5, "accelerometer value", 90);
		StdDraw.text(300, -1.25, "time(ms)");
		
		StdDraw.setFont(font);
		StdDraw.setPenRadius(StdDraw.getPenRadius() / 2);
		for (double d = -0.5; d <= 1.5; d += 0.5) {
			StdDraw.textRight(-5, d, String.valueOf(d));
			StdDraw.line(0, d, 650, d);
		}
		
		for (int i = 100; i <= 600; i += 100) {
			StdDraw.text(i, -1.1, String.valueOf(i));
			StdDraw.line(i, -1, i, 2);
		}
		
	}

}

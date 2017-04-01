package assignment10;

import sedgewick.StdDraw;

public class Chart {

	private double x0, y0, x1, y1;
	
	public Chart(double x0, double y0, double x1, double y1) {
		this.x0 = x0;
		this.y0 = y0;
		this.x1 = x1;
		this.y1 = y1;
	}
	
	public void setXscale(double x0, double x1) {
		this.x0 = x0;
		this.x1 = x1;
	}
	
	public void setYscale(double y0, double y1) {
		this.y0 = y0;
		this.y1 = y1;
	}
	
	public void setPedRadius(double d) {
		StdDraw.setPenRadius();
		double radius = StdDraw.getPenRadius();
		StdDraw.setPenRadius(radius * d);
	}
	
	public void drawChart() {
		StdDraw.enableDoubleBuffering();
		StdDraw.setXscale(this.x0, this.x1);
		StdDraw.setYscale(this.y0, this.y1);
	}
	
	public void eraeChart() {
		StdDraw.clear();
	}
	
	public static void point(double x, double y) {
		StdDraw.point(x, y);
	}
	
	public void points(double[] x, double[] y) {
		for (int i = 0; i < x.length; i++) {
			Chart.point(x[i], y[i]);
		}
	}
	
	public void line(double x0, double y0, double x1, double y1) {
		StdDraw.line(x0, y0, x1, y1);
	}
	
	public void text(double x, double y, String s, String direction) {
		if (direction == "left") StdDraw.textLeft(x, y, s);
		else if (direction == "right") StdDraw.textRight(x, y, s);
		else StdDraw.text(x, y, s);
	}
	
}

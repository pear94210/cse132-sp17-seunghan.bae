package studio0;

public class Heartbeat {

	public static void main(String[] args) {
		
		int n = 1;
		
		while(true) {
			try {
				Thread.sleep(1000);
			} catch(InterruptedException e) {
				e.printStackTrace();
			}
			System.out.println(n + " sec have elapsed");
			n++;
		}
		
	}

}

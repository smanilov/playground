
public class MultiplesLoopRange {
	public static void main(String[] args) {
		int a = Integer.parseInt(args[0]);
		int b = Integer.parseInt(args[1]);
		int step = Integer.parseInt(args[2]);
		
		if (a <= b) {
			System.out.print(a);
			for (int count = a + 1; count <= b; count += step) {
				System.out.print(" " + count);
			}
			System.out.println();
		} else {
			System.out.print(a);
			for (int count = a - step; count >= b; count -= step) {
				System.out.print(" " + count);
			}
			System.out.println();
		}
	}
}

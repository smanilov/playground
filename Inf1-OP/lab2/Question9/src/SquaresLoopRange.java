
public class SquaresLoopRange {
	public static void main(String[] args) {
		int a = Integer.parseInt(args[0]);
		int b = Integer.parseInt(args[1]);
		
		if (a <= b) {
			System.out.print(a * a);
			for (int count = a + 1; count <= b; ++count) {
				System.out.print(" " + count * count);
			}
			System.out.println();
		} else {
			System.out.println("Start-limit greater than stop-limit!");
		}
	}
}

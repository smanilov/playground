
public class Distance1 {
	public static void main(String[] args) {
		int x = Integer.parseInt(args[0]);
		int y = Integer.parseInt(args[1]);
		
		System.out.println(Math.max(x, y) - Math.min(x, y));
	}
}

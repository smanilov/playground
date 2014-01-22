
public class SaferDivider {
	public static void main(String[] args) {
		double x = Double.parseDouble(args[0]);
		double y = Double.parseDouble(args[1]);
		
		if (y != 0.0) {
			double z = x / y;
			System.out.println(z);
		} else {
			System.out.println("I can't divide by zero!");
		}
	}
}

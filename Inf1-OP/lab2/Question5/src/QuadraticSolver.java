
public class QuadraticSolver {
	public static void main(String[] args) {
		double a = Double.parseDouble(args[0]);
		double b = Double.parseDouble(args[1]);
		double c = Double.parseDouble(args[2]);
		
		double d = Math.sqrt(b * b - 4 * a * c);
		double x1 = (-b + d) / (2 * a);
		double x2 = (-b - d) / (2 * a);
		
		System.out.println(x1);
		System.out.println(x2);
	}
}

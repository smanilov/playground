
public class ImQuadraticSolver {
	public static void main(String[] args) {
		double a = Double.parseDouble(args[0]);
		double b = Double.parseDouble(args[1]);
		double c = Double.parseDouble(args[2]);
		
		double dsq = b * b - 4 * a * c;
		if (dsq >= 0) {
			double d = Math.sqrt(dsq);
			if (a != 0) {
				double x1 = (-b + d) / (2 * a);
				double x2 = (-b - d) / (2 * a);
				
				System.out.println(x1);
				System.out.println(x2);
			} else {
				System.out.println(-c / b);
			}
		} else {
			dsq = -dsq;
			double d = Math.sqrt(dsq);
			// if (a != 0) { <= always true, as dsq would not be < 0 if a = 0.
			double real = -b / (2 * a);
			double imag = d / (2 * a);
			
			System.out.println(real + " + " + imag + "i");
			System.out.println(real + " - " + imag + "i");
		}
	}
}

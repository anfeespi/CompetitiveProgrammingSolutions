
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
	public static ArrayList<Double[]> coords;

	public static boolean uebfa(double xpoint, double ypoint, Double... coords) {
		if (xpoint > coords[0] && xpoint < coords[2] && ypoint < coords[1] && ypoint > coords[3])
			return true;
		return false;
	}

	public static void main(String[] args) {
		coords = new ArrayList<Double[]>();

		Scanner sc = new Scanner(System.in);

		String r;
		while (true) {
			r = sc.nextLine();
			if (r.contains("*"))
				break;
			String[] aux = r.split(" ");
			double corner1x = Double.parseDouble(aux[1]), corner1y = Double.parseDouble(aux[2]),
					corner2x = Double.parseDouble(aux[3]), corner2y = Double.parseDouble(aux[4]);

			coords.add(new Double[4]);

			coords.get(coords.size() - 1)[0] = corner1x;
			coords.get(coords.size() - 1)[1] = corner1y;
			coords.get(coords.size() - 1)[2] = corner2x;
			coords.get(coords.size() - 1)[3] = corner2y;
		}

		int pointn = 0;
		while (true) {
			pointn++;
			String line[] = sc.nextLine().split(" ");
			double pointx = Double.parseDouble(line[0]), pointy = Double.parseDouble(line[1]);
			if (pointx >= 9999.9 || pointy >= 9999.9)
				break;

			boolean flag = true;

			for (int figure = 0; figure < coords.size(); figure++) {
				if (uebfa(pointx, pointy, coords.get(figure))) {
					flag = false;
					System.out.println("Point " + pointn + " is contained in figure " + (figure + 1));
				}
			}

			if (flag)
				System.out.println("Point " + pointn + " is not contained in any figure");
		}
	}
}

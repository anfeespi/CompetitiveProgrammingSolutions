
import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int uebfa = sc.nextInt();
		sc.nextLine();
		while(uebfa-- > 0) {
			StringBuilder n1 = new StringBuilder(sc.next()), n2 = new StringBuilder(sc.next());
		
			BigInteger sum = (new BigInteger(n1.reverse().toString())).add(new BigInteger(n2.reverse().toString()));
			
			StringBuilder res = new StringBuilder(sum.toString());
			
			String pr = res.reverse().toString();
			
			boolean flag = true;
			for (int i = 0; i < pr.length(); i++) {
				if(flag && pr.charAt(i) == '0') {
					continue;
				}
				flag = false;
				System.out.print(pr.charAt(i));
			}
			System.out.println();
			
		}
	}
}

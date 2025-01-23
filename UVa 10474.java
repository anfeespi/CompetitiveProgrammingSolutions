import java.util.Arrays;
import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = 1;

        while (true) {
            int n = sc.nextInt(); 
            int q = sc.nextInt(); 

            if (n == 0 && q == 0) {
                break;
            }

            int[] marbles = new int[n];
            for (int i = 0; i < n; i++) {
                marbles[i] = sc.nextInt(); 
            }

            Arrays.sort(marbles); 

            System.out.println("CASE# " + a + ":");

            for (int i = 0; i < q; i++) {
                int consulta = sc.nextInt(); 
                int pos = -1;


                for (int j = 0; j < n; j++) {
                    if (marbles[j] == consulta) {
                        pos = j + 1; 
                        break; 
                    }
                }

                if (pos == -1) {
                    System.out.println(consulta + " not found");
                } else {
                    System.out.println(consulta + " found at " + pos);
                }
            }

            a++;
        }
    }
}

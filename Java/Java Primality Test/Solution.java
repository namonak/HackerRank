import java.util.*;

public class Solution {
    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        String n = scanner.nextLine();

        System.out.println(n.isProbablePrime(100) ? "prime" : "not prime");

        scanner.close();
    }
}

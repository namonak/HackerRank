import java.util.*;
import java.io.*;

class Solution {
    public static void main(String []argh) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();

        for (int i = 0; i < t; i++) {
            try {
                long x = sc.nextLong();
                System.out.println(x+" can be fitted in:");

                // Reference : https://docs.oracle.com/javase/tutorial/java/nutsandbolts/datatypes.html
                if (x >= (byte)(-Math.pow(2, 7)) && x <= (byte)(Math.pow(2, 7) - 1)) {
                    System.out.println("* byte");
                }
                if (x >= (short)(-Math.pow(2, 15)) && x <= (short)(Math.pow(2, 15) - 1)) {
                    System.out.println("* short");
                }
                if (x >= (int)(-Math.pow(2, 31)) && x <= (int)(Math.pow(2, 31) - 1)) {
                    System.out.println("* int");
                }
                if (x >= (long)(-Math.pow(2, 63)) && x <= (long)(Math.pow(2, 63) - 1)) {
                    System.out.println("* long");
                }
            } catch(Exception e) {
                System.out.println(sc.next()+" can't be fitted anywhere.");
            }
        }
    }
}

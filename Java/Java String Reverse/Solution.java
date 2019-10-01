import java.io.*;
import java.util.*;

public class Solution {
    public static void main(String[]args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        /* Enter your code here. Print output to STDOUT. */

        StringBuffer strBuffer = new StringBuffer(s);

        System.out.println(s.equals(strBuffer.reverse().toString())?"Yes":"No");
    }
}

import java.io.*;
import java.util.*;

public class Solution {
	static String reverse(String s){
		return new StringBuffer(s).reverse().toString();
	}
	
	public static void main(String[]args){
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		/* Enter your code here. Print output to STDOUT. */
		
		System.out.println(s.equals(reverse(s)) ? "Yes" : "No");
	}
}

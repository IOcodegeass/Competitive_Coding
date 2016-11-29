import java.util.*;
import java.math.*;

class Main{
	public static void main(String[] args){
		Scanner input = new Scanner(System.in);
		for(int i=0;i<10;i++){
			BigInteger b1 = new BigInteger(input.next());
			BigInteger b2 = new BigInteger(input.next());
			BigInteger b3 = new BigInteger("2");
			BigInteger b4 = b1.add(b2).divide(b3);
			BigInteger b5 = b1.subtract(b4);
			System.out.println(b4);
			System.out.println(b5);
		}
	}
}
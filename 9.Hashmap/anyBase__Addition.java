//>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>Any Base Addition
/*
QUESTION
    1. You are given a base b.
    2. You are given two numbers n1 and n2 of base b.
    3. You are required to add the two numbes and print their value in base b.
   

SAMPLE INPUT 8
             777
             1
SAMPLE OUTPUT:205

*/
import java.util.*;

public class anyBase__Addition{

  public static void main(String[] args) {
    
    Scanner scn = new Scanner(System.in);
    
    int b = scn.nextInt();
    int n1 = scn.nextInt();
    int n2 = scn.nextInt();
        
    int d= getSum(b, n1,n2);
    System.out.println(d);
  }

  public static int getSum(int b, int n1, int n2){
    int ans=0; 
    int pow = 1;
    int carry =0;

    while(n1>0 || n2>0 || carry>0){
      int d1 = n1%10; 
      n1=n1/10;
      
      int d2 = n2%10; 
      n2=n2/10;

      int num = n1+n2+carry;

      carry = num /b; //update carry;
      num = num%b; //update num;
           
      ans = ans+num*pow; //update ans;
      pow = pow*10; //update ans;
    }
    return ans;
  }
}
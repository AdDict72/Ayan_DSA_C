import java.util.Scanner;

public class ReverseNum {
    static int rev(int n){
        int num = n;
        int r = 0;
        while (num>0) {
        int remainder = num%10;
        r = r*10+remainder;   
        num = num/10;         
        }
        return r;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Intput: ");
        int N = sc.nextInt();

        int R = rev(N);
        System.out.println("Reversed Number: "+R);
        sc.close();
    }
}

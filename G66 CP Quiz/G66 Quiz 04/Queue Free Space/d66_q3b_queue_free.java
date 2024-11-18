import java.util.Scanner;
public class d66_q3b_queue_free
{
    public static void main(String[] args) {
        double mSize = 0, mCap = 1;
        try (Scanner Scanner = new Scanner(System.in)) {
            int n = Scanner.nextInt();
            for(int i = 0; i < n; i++)
            {
                int t = Scanner.nextInt();
                int k = Scanner.nextInt();
                if(t == 0) { mSize += k; }
                if(t == 1) { mSize -= k; }
                if(mCap < mSize) { mCap = Math.pow(2, Math.ceil(Math.log(mSize)/Math.log(2))); }
            }
        }
        System.out.println(Math.round(mCap - mSize));
    }
}
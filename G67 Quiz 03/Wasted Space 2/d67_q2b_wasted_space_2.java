import java.util.Scanner;

public class d67_q2b_wasted_space_2
{
    public static void main(String[] args)
    {
        Scanner Scanner = new Scanner(System.in);
        long mSize = 0, mCap = 1;
        int t = Scanner.nextInt();
        for(int i = 0; i < t; i++)
        {
            String command = Scanner.next();
            long n = Scanner.nextLong();
            if(command.equals("p")) { mSize += n; }
            if(command.equals("o")) { mSize -= n; }
            if(command.equals("r"))
            {
                mSize = n;
                if(n > mCap) mCap = n;
            }
            while(mSize > mCap) { mCap *= 2; }
        }
        Scanner.close();
        System.out.println(mCap - mSize);
    }
}
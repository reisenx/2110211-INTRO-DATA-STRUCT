import java.util.Scanner;
public class d64_q3a_queue_check
{
    public static void main(String[] args) {
        Scanner Scanner = new Scanner(System.in);
        int n = Scanner.nextInt();
        for(int i = 0; i < n; i++)
        {
            int mFront = Scanner.nextInt();
            int mSize = Scanner.nextInt();
            int mCap = Scanner.nextInt();
            int last = Scanner.nextInt();
            int correction = Scanner.nextInt();
            if(mSize > mCap || last >= mCap || mFront >= mCap || last != (mFront+mSize) % mCap)
            {
                if(correction == 0) System.out.println("WRONG");
                if(correction == 1)
                {
                    System.out.println("WRONG " + ((last + mCap - mSize) % mCap));
                }
                if(correction == 2)
                {
                    System.out.println("WRONG " + ((mCap + last - mFront) % mCap));
                }
                if(correction == 3)
                {
                    if(mFront < last) System.out.println("WRONG " + (last+1));
                    else System.out.println("WRONG " + (mSize + mFront - last));
                }
                if(correction == 4)
                {
                    System.out.println("WRONG " + ((mFront + mSize) % mCap));
                }
            }
            else System.out.println("OK");
        }
        Scanner.close();
    }
}
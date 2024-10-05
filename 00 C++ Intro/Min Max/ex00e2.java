import java.util.Scanner;

public class ex00e2
{
    public static void main(String args[])
    {
        // Input rows(N) and columns(M) values
        try (Scanner Scanner = new Scanner(System.in)) {
            int N = Scanner.nextInt();
            int M = Scanner.nextInt();
            int R = Scanner.nextInt();
            int[][] mat = new int[105][105];
            
            // Input 2D Array
            for(int row=1; row<=N; row++)
            {
                for(int col=1; col<=M; col++)
                {
                    mat[row][col] = Scanner.nextInt();
                }
            }
            
            // Output
            for(int i=0; i<R; i++)
            {
                // Input top-left and bottom-right of the region
                int r1 = Scanner.nextInt();
                int c1 = Scanner.nextInt();
                int r2 = Scanner.nextInt();
                int c2 = Scanner.nextInt();
                
                // Check Invalid and Outside region
                if(r1 > r2 || c1 > c2)
                {
                    System.out.println("INVALID");
                }
                else if((r1 < 1 && r2 < 1) || (r1 > N && r2 > N))
                {
                    System.out.println("OUTSIDE");
                }
                else if((c1 < 1 && c2 < 1) || (c1 > M && c2 > M))
                {
                    System.out.println("OUTSIDE");
                }
                else
                {
                    // Find the maximum value in the region
                    r1 = Math.max(1, r1);
                    c1 = Math.max(1,c1);
                    r2 = Math.min(N, r2);
                    c2 = Math.min(M, c2);
                    int MAX = mat[r1][c1];
                    for(int row = r1; row <= r2; row++)
                    {
                        for(int col = c1; col <= c2; col++)
                        {
                            if(mat[row][col] > MAX)
                            {
                                MAX = mat[row][col];
                            }
                        }
                    }
                    System.out.println(MAX);
                }
            }
        }
    }
}
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class d65_q1b_cross_2d
{
    public static void main(String[] args) {
        try(BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));)
        {
            String line = reader.readLine();
            String[] data = line.split(" ");
            int row = Integer.parseInt(data[0]);
            int col = Integer.parseInt(data[1]);
            
            line = reader.readLine();
            data = line.split(" ");
            int r1 = Integer.parseInt(data[0]);
            int r2 = Integer.parseInt(data[1]);
            int c1 = Integer.parseInt(data[2]);
            int c2 = Integer.parseInt(data[3]);
            for(int r = 0; r < row; r++)
            {
                line = reader.readLine();
                if(r >= r1 && r <= r2) continue;
                data = line.split(" ");
                for(int c = 0; c < col; c++)
                {
                    if(c >= c1 && c <= c2) continue;
                    System.out.print(data[c]);
                    System.out.print(" ");
                }
                System.out.print("\n");
            }
            reader.close();
        }
        catch(IOException e) {}
    }
}
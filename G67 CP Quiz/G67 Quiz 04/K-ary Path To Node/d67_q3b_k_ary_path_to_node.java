import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayDeque;

public class d67_q3b_k_ary_path_to_node
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader Scanner = new BufferedReader(new InputStreamReader(System.in));
        String[] input = Scanner.readLine().split(" ");
        long N = Long.parseLong(input[0]);
        long K = Long.parseLong(input[1]);
        long node = Long.parseLong(Scanner.readLine());
        
        ArrayDeque<Long> paths = new ArrayDeque<>();
        while(node > 0)
        {
            paths.push((node-1) % K);
            node = (node-1)/K;
        }
        
        StringBuilder output = new StringBuilder();
        output.append(paths.size()).append("\n");
        while (!paths.isEmpty())
        {
            output.append(paths.pop()).append(" ");
        }
        System.out.print(output);
    }
}
import java.io.*;
import java.lang.reflect.Array;
import java.util.*;

class Solution {

    // Complete the organizingContainers function below.
    static String organizingContainers(int[][] container) {
        long[] rows = new long[container.length];
        long[] cols = new long[container.length];
        for(int i = 0; i < container.length; i++){
            for(int j = 0; j < container.length; j++){
                rows[i] += container[i][j];
                cols[j] += container[i][j];
            }
        }
        Arrays.sort(rows);
        Arrays.sort(cols);
        if(Arrays.equals(rows, cols)) return "Possible";
        return "Impossible";
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {

        Scanner in = new Scanner(System.in);
        int q = in.nextInt();
        String answer="";
        while(q-->0)
        {
            int n = in.nextInt();
            int[][] M = new int[n][n];
            for(int i=0; i < n; i++)
                for(int j=0; j < n; j++)
                    M[i][j] = in.nextInt();
            String result= organizingContainers(M);
            if (answer.equals(""))
            {
                answer= result;
            }
            else
            {
                answer= answer + ","+result;
            }
        }

        // Do not remove below line
        System.out.println(answer);
        // Do not print anything after this line

        scanner.close();
    }
}
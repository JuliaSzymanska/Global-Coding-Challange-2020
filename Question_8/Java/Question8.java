import java.io.*;
import java.util.*;
import java.util.stream.Stream;

class Solution {
    static long countNumberOfWays(int numOfUnits, int numOfCoinTypes, int[] coins) {
        long[] table = new long[numOfUnits + 1];
        Arrays.fill(table, 0);
        table[0] = 1;
        for (int i = 0; i < numOfCoinTypes; i++)
            for (int j = coins[i]; j <= numOfUnits; j++)
                table[j] += table[j - coins[i]];
        return table[numOfUnits];
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        String[] firstLine = scanner.nextLine().split(" ");
        String[] secondLine = scanner.nextLine().split(" ");
        scanner.close();

        int numOfUnits = Integer.parseInt(firstLine[0]);
        int numOfCoinTypes = Integer.parseInt(firstLine[1]);
        int[] coins = Stream.of(secondLine).mapToInt(Integer::parseInt).toArray();

        long result = countNumberOfWays(numOfUnits, numOfCoinTypes, coins);
        // Please do not remove the below line.
        System.out.println(result);
        // Do not print anything after this line
    }
}

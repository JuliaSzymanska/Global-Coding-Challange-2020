import java.io.*;
import java.util.*;
import java.util.stream.Stream;

class Solution {

    static int findMaxProfit(int numOfPredictedTimes, int[] predictedSharePrices) {
        int result = 0;
        int k = 0;
        for (int i = 0; i < numOfPredictedTimes - 1; i++) {
        if (predictedSharePrices[i + 1] - predictedSharePrices[i] > 0)
            result += predictedSharePrices[i + 1] - predictedSharePrices[i];
        }
        return result;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        String[] firstLine = scanner.nextLine().split(" ");
        int[] firstLineArr = Stream.of(firstLine).mapToInt(Integer::parseInt).toArray();
        int numOfPredictedTimes = firstLineArr[0];
        int[] predictedSharePrices = Arrays.copyOfRange(firstLineArr, 1, firstLineArr.length);
        scanner.close();

        int result = findMaxProfit(numOfPredictedTimes, predictedSharePrices);
        // Please do not remove the below line.
        System.out.println(result);
        // Do not print anything after this line
    }
}

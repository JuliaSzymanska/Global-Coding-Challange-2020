import java.io.*;
import java.util.*;
import java.util.stream.Stream;

class Solution {

    static int findMaxProfit(int numOfPredictedDays, int[] predictedSharePrices) {
        int max = predictedSharePrices[1] - predictedSharePrices[0];
        for (int i = 0; i < numOfPredictedDays; i++) {
            for (int j = i + 1; j < numOfPredictedDays; j++) {
                int temp = predictedSharePrices[j] - predictedSharePrices[i];
                if (temp > max)
                    max = temp;
            }
        }
        return max;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        String[] firstLine = scanner.nextLine().split(" ");
        int[] firstLineArr = Stream.of(firstLine).mapToInt(Integer::parseInt).toArray();
        int numOfPredictedDays = firstLineArr[0];
        int[] predictedSharePrices = Arrays.copyOfRange(firstLineArr, 1, firstLineArr.length);
        scanner.close();

        int result = findMaxProfit(numOfPredictedDays, predictedSharePrices);
        // Do not remove this line
        System.out.println(result);
        // Do not print anything after this line
    }
}
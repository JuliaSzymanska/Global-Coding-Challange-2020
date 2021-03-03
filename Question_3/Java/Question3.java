import java.io.*;
import java.util.*;

class Solution {

    public static void main(String[] args) {

        try (Scanner scanner = new Scanner(System.in)) {
            int n = scanner.nextInt();
            int d = scanner.nextInt();
            String answer = "";
            int[] values = new int[n];
            int[] profit = new int[d];
            for (int i = 0; i < n; i++) {
                values[i] = scanner.nextInt();
            }

            for (int j = 0; j < d; j++) {
                profit[j] = scanner.nextInt();
            }
            answer = findMinDays(values, profit);
            System.out.println(answer);
        }
    }

    public static String findMinDays(int[] values, int[] profit) {
        StringBuilder str = new StringBuilder();
        for (int k = 0; k < profit.length; k++) {
            List<int[]> listN = new ArrayList<>();
            for (int i = 0; i < values.length; i++) {
                for (int j = i + 1; j < values.length; j++) {
                    if (values[j] - values[i] == profit[k]) {
                        listN.add(new int[]{i + 1, j + 1});
                    }
                }
            }
            int index = 0;
            for (int i = 1; i < listN.size(); i++) {
                if (listN.get(i)[1] < listN.get(index)[1]) {
                    index = i;
                } else if (listN.get(i)[1] == listN.get(index)[1]) {
                    int first = listN.get(i)[1] - listN.get(i)[0];
                    int second = listN.get(index)[1] - listN.get(index)[0];
                    if (second > first) {
                        index = i;
                    }
                }
            }

            if (k != 0) str.append(",");
            if (listN.isEmpty()) {
                str.append("-1");
            } else {
                str.append(listN.get(index)[0]);
                str.append(" ");
                str.append(listN.get(index)[1]);
            }
        }
        return str.toString();
    }
}
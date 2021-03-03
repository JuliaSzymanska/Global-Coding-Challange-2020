import java.io.*;
import java.text.DecimalFormat;
import java.util.*;

class Solution {
    public static double maximumExpectedMoney(int n, int m, double[] p, double[] x, double[] y) {
        List<Double> money = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            money.add((p[i] * x[i]) - ((1 - p[i]) * y[i]));
        }
        double result = 0;
        for (int i = 0; i < m; i++) {
            double max = Collections.max(money);
            if (max > 0)
                result += max;
            money.remove(max);
        }
        return result;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        Scanner in = new Scanner(System.in);

        int n = in.nextInt();
        int m = in.nextInt();

        double[] p = new double[n];
        double[] x = new double[n];
        double[] y = new double[n];
        double result = 0;

        for (int i = 0; i < n; i++)
            p[i] = in.nextDouble();
        for (int i = 0; i < n; i++)
            x[i] = in.nextDouble();
        for (int i = 0; i < n; i++)
            y[i] = in.nextDouble();

        result = maximumExpectedMoney(n, m, p, x, y);
        DecimalFormat f = new DecimalFormat("#0.00");

        System.out.println(f.format(result));

        in.close();
    }
}
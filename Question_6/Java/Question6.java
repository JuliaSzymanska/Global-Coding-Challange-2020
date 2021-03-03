import java.io.*;
import java.util.*;

class Solution {

    static String encrypt(String words) {
        String t = words.replaceAll(" ", "");
        int row = (int) Math.floor(Math.sqrt(t.length()));
        int col = (int) Math.ceil(Math.sqrt(t.length()));
        if ((row * col) < t.length()) row++;
        char[][] encrypt = new char[row][col];
        int k = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (k < t.length()) {
                    encrypt[i][j] = t.charAt(k);
                    k++;
                }
            }
        }
        StringBuilder str = new StringBuilder();
        for (int i = 0; i < col; i++) {
            for (int j = 0; j < row; j++) {
                if ((int) (encrypt[j][i]) != 0)
                    str.append(encrypt[j][i]);
            }
            str.append(" ");
        }
        return str.toString();
    }


    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        String words = scanner.nextLine();
        scanner.close();

        String result = encrypt(words);
        // Please do not remove the below line.
        System.out.println(result);
        // Do nore print anything after this line
    }
}
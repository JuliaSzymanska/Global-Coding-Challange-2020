import java.io.*;
import java.util.*;
import java.util.stream.Stream;

class Solution {
    static String findSuspiciousUserId(int numOfQuestions, int[][] questionAndAnswerArrOfArr) {
        Set suspicious = new TreeSet();
        for (int[] ints : questionAndAnswerArrOfArr) {
            for (int[] value : questionAndAnswerArrOfArr) {
                if (value[0] != ints[0] && find(value, ints[0]) && find(ints, value[0])) {
                    suspicious.add(value[0]);
                }
            }
        }
        int num = 0;
        while (num != suspicious.size()) {
            num = suspicious.size();
            for (int[] ints : questionAndAnswerArrOfArr) {
                if (!suspicious.contains(ints[0])) {
                    int i = 0;
                    for (int j = 1; j < ints.length; j++) {
                        if (suspicious.contains(ints[j])) {
                            i++;
                        }
                        if (i >= 2) {
                            suspicious.add(ints[0]);
                            break;
                        }
                    }

                }
            }
        }
        StringBuilder stringBuilder = new StringBuilder();
        for (Object i : suspicious) {
            stringBuilder.append(i);
            stringBuilder.append(",");
        }
        stringBuilder.deleteCharAt(stringBuilder.length() - 1 );
        return stringBuilder.toString();
    }

    private static boolean find(int[] array, int value) {
        for (int a : array) {
            if (a == value) {
                return true;
            }
        }
        return false;
    }

    private static final Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) throws IOException {
        // Sample input:
        // 3
        // 1 2,2 1,3 1 2
        String[] firstLine = scanner.nextLine().split(" ");
        String secondLine = scanner.nextLine();
        scanner.close();

        int numOfQuestions = Integer.parseInt(firstLine[0]);
        String[] questionAndAnswers = secondLine.split(",");
        int[][] questionAndAnswerArrOfArr = parseQuestionAndAnswer(questionAndAnswers);

        String result = findSuspiciousUserId(numOfQuestions, questionAndAnswerArrOfArr);
        // Please do not remove the below line.
        System.out.println(result);
        // Do not print anything after this line
    }

    private static int[][] parseQuestionAndAnswer(String[] questionAndAnswers) {
        return Arrays.stream(questionAndAnswers)
                .map(questionAndAnswer -> {
                    String[] questionAndAnswerArr = questionAndAnswer.split(" ");
                    return Stream.of(questionAndAnswerArr).mapToInt(Integer::parseInt).toArray();
                })
                .toArray(int[][]::new);
    }
}
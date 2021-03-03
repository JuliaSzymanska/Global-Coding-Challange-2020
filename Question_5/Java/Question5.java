import java.io.*;
import java.util.*;
import java.util.stream.Stream;

class Solution {

    static int calculateMinimumSession(int numOfBankers, int numOfParticipants, int[][] bankersPreferences, int[][] participantsPreferences) {
        int[] participant = new int[numOfParticipants];
        int[] bankers = new int[numOfBankers];
        matcher(participantsPreferences, bankersPreferences, participant, bankers);
        matcher(bankersPreferences, participantsPreferences, bankers, participant);
        Arrays.sort(participant);
        Arrays.sort(bankers);
        return Math.max(participant[numOfParticipants -1], bankers[numOfBankers - 1]);
    }

    private static void matcher(int[][] pref, int[][] pref2, int[] list, int[] list2){
        for (int i = 0; i < pref.length; i++) {
            for (int j = 0; j < pref[i].length; j++) {
                list2[pref[i][j] - 1]++;
                int index = pref[i][j] - 1;
                if (!find(pref2[index], i + 1)) {
                    list[i]++;
                }
            }
        }
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
        // 3 1,1,1&2
        // 3 3&2,1,1
        String[] firstLine = scanner.nextLine().split(" ");
        String[] secondLine = scanner.nextLine().split(" ");
        scanner.close();

        int numOfBankers = Integer.parseInt(firstLine[0]);
        int numOfParticipants = Integer.parseInt(secondLine[0]);

        String[] bankersPreferences = firstLine[1].split(",");
        String[] participantsPreferences = secondLine[1].split(",");

        int[][] bankersPreferencesArrOfArr = parsePreferences(bankersPreferences);
        int[][] participantsPreferencesArrOfArr = parsePreferences(participantsPreferences);


        int result = calculateMinimumSession(numOfBankers, numOfParticipants, bankersPreferencesArrOfArr, participantsPreferencesArrOfArr);
        // Please do not remove the below line.
        System.out.println(result);
        // Do not print anything after this line
    }

    private static int[][] parsePreferences(String[] preferences) {
        return Arrays.stream(preferences)
                .map(preference -> {
                    String[] preferenceArr = preference.split("&");
                    return Stream.of(preferenceArr).mapToInt(Integer::parseInt).toArray();
                })
                .toArray(int[][]::new);
    }
}

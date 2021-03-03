#include <bits/stdc++.h>

using namespace std;

int calculateMinimumSession(int numOfBankers, int numOfParticipants, vector<vector<int>> bankersPreferences,
                            vector<vector<int>> participantsPreferences) {
    int participant[numOfParticipants]{0};
    int bankers[numOfBankers]{0};
    int minimum = 0;
    for (int i = 0; i < numOfParticipants; i++) {
        for (int j = 0; j < participantsPreferences[i].size(); j++) {
            bankers[participantsPreferences[i][j] - 1]++;
            if (bankers[participantsPreferences[i][j] - 1] > minimum)
                minimum = bankers[participantsPreferences[i][j] - 1];
            participant[i]++;
            if (participant[i] > minimum) minimum = participant[i];
        }
    }
    for (int i = 0; i < numOfBankers; i++) {
        for (int j = 0; j < bankersPreferences[i].size(); j++) {
            if (!(find(participantsPreferences[bankersPreferences[i][j] - 1].begin(),
                       participantsPreferences[bankersPreferences[i][j] - 1].end(),
                       i + 1) != participantsPreferences[bankersPreferences[i][j] - 1].end())) {
                bankers[i]++;
                if (bankers[i] > minimum) minimum = bankers[i];
                participant[bankersPreferences[i][j] - 1]++;
                if (participant[bankersPreferences[i][j] - 1] > minimum)
                    minimum = participant[bankersPreferences[i][j] - 1];
            }
        }
    }
    return minimum;
}


vector<string> split(const string &str, char delim) {
    vector<string> strings;
    size_t start;
    size_t end = 0;
    while ((start = str.find_first_not_of(delim, end)) != string::npos) {
        end = str.find(delim, start);
        strings.push_back(str.substr(start, end - start));
    }
    return strings;
}

vector<int> splitStringToInt(const string &str, char delim) {
    vector<int> strings;
    size_t start;
    size_t end = 0;
    while ((start = str.find_first_not_of(delim, end)) != string::npos) {
        end = str.find(delim, start);
        strings.push_back(stoi(str.substr(start, end - start)));
    }
    return strings;
}

void printVector(vector<int> vec) {
    for (vector<int>::const_iterator i = vec.begin(); i != vec.end(); ++i) {
        cout << *i << ' ';
    }
    cout << endl;
}

void printVector(vector<string> vec) {
    for (vector<string>::const_iterator i = vec.begin(); i != vec.end(); ++i) {
        cout << *i << ' ';
    }
    cout << endl;
}

int main() {
    int numOfBankers, numOfParticipants;
    vector<vector<int>> bankersPreferences, participantsPreferences;

    cin >> numOfBankers;

    string bankersPreferencesStr;
    cin >> bankersPreferencesStr;
    vector<string> bankersPreferencesVecByComma = split(bankersPreferencesStr, ',');

    for (vector<string>::const_iterator i = bankersPreferencesVecByComma.begin();
         i != bankersPreferencesVecByComma.end(); ++i) {
        vector<int> bankerPreferenceVecByAnd = splitStringToInt(*i, '&');
        bankersPreferences.push_back(bankerPreferenceVecByAnd);
    }

    string participantsPreferencesStr;
    cin >> numOfParticipants;
    cin >> participantsPreferencesStr;
    vector<string> participantsPreferencesVecByComma = split(participantsPreferencesStr, ',');

    for (vector<string>::const_iterator i = participantsPreferencesVecByComma.begin();
         i != participantsPreferencesVecByComma.end(); ++i) {
        vector<int> participantPreferenceVecByAnd = splitStringToInt(*i, '&');
        participantsPreferences.push_back(participantPreferenceVecByAnd);
    }
    int result = calculateMinimumSession(numOfBankers, numOfParticipants, bankersPreferences, participantsPreferences);
    // Do not remove below line
    cout << result << "\n";
    // Do not print anything after this line

    return 0;
}


//int calculateMinimumSession(int numOfBankers, int numOfParticipants, vector<vector<int>> bankersPreferences,
//                            vector<vector<int>> participantsPreferences) {
//    int participant[numOfParticipants]{0};
//    int bankers[numOfBankers]{0};
//    int minimum = 0;
//    for (int i = 0; i < numOfParticipants; i++) {
//        for (int j = 0; j < participantsPreferences[i].size(); j++) {
//            bankers[participantsPreferences[i][j] - 1]++;
//            if (bankers[participantsPreferences[i][j] - 1] > minimum)
//                minimum = bankers[participantsPreferences[i][j] - 1];
//            if (!(find(bankersPreferences[participantsPreferences[i][j] - 1].begin(),
//                       bankersPreferences[participantsPreferences[i][j] - 1].end(),
//                       i + 1) != bankersPreferences[participantsPreferences[i][j] - 1].end())) {
//                participant[i]++;
//                if (participant[i] > minimum) minimum = participant[i];
//            }
//        }
//    }
//    for (int i = 0; i < numOfBankers; i++) {
//        for (int j = 0; j < bankersPreferences[i].size(); j++) {
//            participant[bankersPreferences[i][j] - 1]++;
//            if(participant[bankersPreferences[i][j] - 1] > minimum)
//                minimum = participant[bankersPreferences[i][j] - 1];
//            if (!(find(participantsPreferences[bankersPreferences[i][j] - 1].begin(),
//                       participantsPreferences[bankersPreferences[i][j] - 1].end(),
//                       i + 1) != participantsPreferences[bankersPreferences[i][j] - 1].end())) {
//                bankers[i]++;
//                if(bankers[i] > minimum) minimum = bankers[i];
//            }
//        }
//    }
//    return minimum;
//}
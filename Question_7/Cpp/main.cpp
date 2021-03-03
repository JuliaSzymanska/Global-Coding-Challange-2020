#include <bits/stdc++.h>

using namespace std;

string findSuspiciousUserId(vector<vector<int>> questionAndAnswerVecOfVec) {
    int max = 0;
    for (auto &i : questionAndAnswerVecOfVec) {
        if (max < i[0])
            max = i[0];
    }
    bool suspicious[max + 1];
    for(int i = 0; i < max + 1; i++){
        suspicious[i] = false;
    }
    for (auto &ints : questionAndAnswerVecOfVec) {
        for (auto &value : questionAndAnswerVecOfVec) {
            if (value[0] != ints[0] &&
                find(value.begin(), value.end(), ints[0]) != value.end() &&
                find(ints.begin(), ints.end(), value[0]) != ints.end()) {
                suspicious[value[0]] = true;
                suspicious[ints[0]] = true;
            }
        }
    }
    int suspiciousCount = 0;
    int previous = -1;
    while (previous < suspiciousCount) {
        previous = suspiciousCount;
        for (auto &ints : questionAndAnswerVecOfVec) {
            if (!suspicious[ints[0]]) {
                int i = 0;
                for (auto &j : ints) {
                    if (suspicious[j]) {
                        i++;
                        if (i == 2) {
                            suspicious[ints[0]] = true;
                            suspiciousCount++;
                            break;
                        }
                    }
                }
            }
        }
    }
    string result;
    for (int i = 1; i < max + 1; i++) {
        if (suspicious[i]) result += std::to_string(i) + ",";
    }
    return result.substr(0, result.length() - 1);
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
    string firstLine;
    getline(cin, firstLine);

    int numOfQuestions = strtol(firstLine.c_str(), NULL, 10);;

    string questionAndAnswerStr;
    getline(cin, questionAndAnswerStr);

    vector<vector<int>> questionAndAnswerVecOfVec;
    vector<string> questionAndAnswerVecByComma = split(questionAndAnswerStr, ',');

    for (vector<string>::const_iterator i = questionAndAnswerVecByComma.begin();
         i != questionAndAnswerVecByComma.end(); ++i) {
        vector<int> bankerPreferenceVecByAnd = splitStringToInt(*i, ' ');
        questionAndAnswerVecOfVec.push_back(bankerPreferenceVecByAnd);
    }

    string result = findSuspiciousUserId(questionAndAnswerVecOfVec);

    // Do not remove below line
    cout << result << "\n";
    // Do not print anything after this line

    return 0;
}
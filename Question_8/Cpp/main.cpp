#include <bits/stdc++.h>

using namespace std;

long countNumberOfWays(int numOfUnits, int numOfCoinTypes, vector<int> coins) {
    long table[numOfUnits + 1];
    for (int i = 0; i < (numOfUnits + 1); i++) {
        table[i] = 0;
    }
    table[0] = 1;
    for (int i = 0; i < numOfCoinTypes; i++)
        for (int j = coins[i]; j <= numOfUnits; j++)
            table[j] += table[j - coins[i]];
    return table[numOfUnits];
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

    vector<int> firstLineVec = splitStringToInt(firstLine, ' ');
    int numOfUnits = firstLineVec[0];
    int numOfCoinTypes = firstLineVec[1];

    string coins;
    getline(cin, coins);

    vector<int> coinsVec = splitStringToInt(coins, ' ');

    long result = countNumberOfWays(numOfUnits, numOfCoinTypes, coinsVec);

    // Do not remove below line
    cout << result << "\n";
    // Do not print anything after this line

    return 0;
}

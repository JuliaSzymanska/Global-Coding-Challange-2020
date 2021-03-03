#include <bits/stdc++.h>

using namespace std;

int findMaxProfit(int numOfPredictedDays, vector<int> predictedSharePrices) {
    int max = predictedSharePrices[1] - predictedSharePrices[0];
    int min = predictedSharePrices[0];
    for (int i = 1; i < numOfPredictedDays; i++) {
        if (predictedSharePrices[i] - min > max)
            max = predictedSharePrices[i] - min;
        if (predictedSharePrices[i] < min)
            min = predictedSharePrices[i];
    }
    return max;
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

int main() {
    string firstLine;
    getline(cin, firstLine);

    vector<int> firstLineVec = splitStringToInt(firstLine, ' ');
    int numOfPredictedDays = firstLineVec[0];
    vector<int> predictedSharePrices(firstLineVec.begin() + 1, firstLineVec.end());


    int result = findMaxProfit(numOfPredictedDays, predictedSharePrices);

    // Do not remove this line
    cout << result << "\n";
    // Do not print anything after this line

    return 0;
}
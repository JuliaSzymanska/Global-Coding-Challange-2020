#include <bits/stdc++.h>
#include <cmath>

using namespace std;

string encrypt(string words) {
    words.erase(remove(words.begin(), words.end(), ' '), words.end());
    int row = (int) floor(sqrt(words.length()));
    int col = (int) ceil(sqrt(words.length()));
    if ((row * col) < words.length()) row++;
    string str;
    int k = 0;
    int i = 0;
    while (i < row * col - 1) {
        if (i < words.length())
            str += words.at(i);
        if (i == col * (row - 1) + k) {
            k++;
            i = k;
            str += " ";
        } else {
            i += col;
        }
    }
    return str;
}


int main() {
    string words;
    getline(cin, words);

    string result = encrypt(words);

    // Do not remove below line
    cout << result << "\n";
    // Do not print anything after this line

    return 0;
}
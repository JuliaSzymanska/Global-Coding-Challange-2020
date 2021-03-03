#include <map>
#include <deque>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

string organizingContainers(vector<vector<int> > M) {
    int rows[M.size()] = {0};
    int cols[M.size()] = {0};
    for (int i = 0; i < M.size(); i++) {
        for (int j = 0; j < M.size(); j++) {
            rows[i] += M[i][j];
            cols[j] += M[i][j];
        }
    }
    sort(rows, rows + M.size());
    sort(cols, cols + M.size());
    for (int j = 0; j < M.size(); j++)
        if (rows[j] != cols[j])
            return "Impossible";
    return "Possible";
}

int main() {
    int q;
    cin >> q;
    string answer;
    for (int a0 = 0; a0 < q; a0++) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n));
        for (int M_i = 0; M_i < n; M_i++) {
            for (int M_j = 0; M_j < n; M_j++) {
                cin >> M[M_i][M_j];
            }
        }

        string result = organizingContainers(M);
        if (answer.empty())
            answer = result;
        else
            answer = answer + "," + result;
    }
    cout << answer << endl;

    return 0;
}
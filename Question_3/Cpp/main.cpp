#include<bits/stdc++.h>

using namespace std;

string find_min_days(int profit[], int price[]) {
    string str;
    for (int k = 0; k < sizeof(profit)/sizeof(profit[0]); k++) {
        List<int[]> listN = new ArrayList<>();
        for (int i = 0; i < sizeof(price)/sizeof(price[0]); i++) {
            for (int j = i + 1; j < sizeof(price)/sizeof(price[0]); j++) {
                if (price[j] - price[i] == profit[k]) {
                    listN.add(new int[]{i + 1, j + 1});
                }
            }
        }
        int index = 0;
        for (int i = 1; i < listN.size(); i++) {
            if (listN.get(i)[1] < listN.get(index)[1]) {
                index = i;
            } else if (listN.get(i)[1] == listN.get(index)[1]) {
                int first = listN.get(i)[1] - listN.get(i)[0];
                int second = listN.get(index)[1] - listN.get(index)[0];
                if (second > first) {
                    index = i;
                }
            }
        }

        if (k != 0) str.append(",");
        if (listN.isEmpty()) {
            str.append("-1");
        } else {
            str.append(listN.get(index)[0]);
            str.append(" ");
            str.append(listN.get(index)[1]);
        }
    }
    return str.toString();
}

int main() {
    int n, d, i;
    string answer = "";
    cin >> n >> d;
    int price[n];
    int profit[d];
    for (i = 0; i < n; i++)
        cin >> price[i];
    for (i = 0; i < d; i++)
        cin >> profit[i];
    answer = find_min_days(profit, price);

    // Do not remove below line
    cout << answer << endl;
    // Do not print anything after this line

    return 0;
}
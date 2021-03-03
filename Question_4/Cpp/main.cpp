#include<bits/stdc++.h>

using namespace std;

double maximumExpectedMoney(int n, int m, double p[], double x[], double y[]) {

    double money[n] = {0.00};
    for (int i = 0; i < n; i++) {
        double wyn = ((p[i] * x[i]) - ((1 - p[i]) * y[i]));
        if ( wyn > 0){
            money[i] = wyn;}
        cout << wyn << endl;
    }
    sort(money, money + n, greater<>());
    double result = 0.00;

    if(m > n){
        m = n;
    }

    for (int i = 0; i < m; i++) {
        if (money[i] == 0.00) break;
        result += money[i];
    }
    cout << result << endl;
    cout << round(result*100) / 100 << endl;
    return result;
}


int main() {
    int n, m;
    cin >> n >> m;
    double p[n], x[n], y[n];
    for (int i = 0; i < n; i++)
        cin >> p[i];
    for (int i = 0; i < n; i++)
        cin >> x[i];
    for (int i = 0; i < n; i++)
        cin >> y[i];
    double result = maximumExpectedMoney(n, m, p, x, y);
    cout << fixed << setprecision(2) << result << endl;
    return 0;
}
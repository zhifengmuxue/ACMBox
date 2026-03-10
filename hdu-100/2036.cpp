#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;

        vector<long long> x(n), y(n);
        for (int i = 0; i < n; i++) {
            cin >> x[i] >> y[i];
        }

        long long sum = 0;
        for (int i = 0; i < n; i++) {
            int j = (i + 1) % n;  
            sum += x[i] * y[j] - x[j] * y[i];
        }

        double area = fabs(sum) / 2.0;
        cout << fixed << setprecision(1) << area << endl;
    }

    return 0;
}
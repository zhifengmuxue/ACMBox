#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
double x1, y1, x2, y2;

int main() {
    while (cin >> x1 >> y1 >> x2 >> y2) {
        double dx = x1 - x2;
        double dy = y1 - y2;
        double result = sqrt(dx * dx + dy * dy);
        cout << fixed << setprecision(2) << result << endl;
    }
    return 0;
}

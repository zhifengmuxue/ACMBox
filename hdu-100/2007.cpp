#include <iostream>
using namespace std;

int main() {
    int st, e;
    while (cin >> st >> e) {
        long long f = 0, s = 0;
        int l = min(st, e);
        int r = max(st, e);

        for (int i = l; i <= r; i++) {
            if (i % 2 == 0)
                f += (long long)i * i;       
            else
                s += (long long)i * i * i;   
        }

        cout << f << " " << s << endl;
    }
    return 0;
}

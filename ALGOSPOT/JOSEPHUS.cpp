#include <iostream>
#include <cstring>

using namespace std;

int N, K, remains;
int r[1000];

void josephus (void) {
    int p = 0, roul = 2;
    remains = N;
    while (remains != 2) {
        if (r[p] == 0 && ++roul == 3) {
            #ifdef PPRINT
            cout << "hit the " << p << "\n";
            #endif
            r[p] = 1;
            remains--;
        }
        p++;
        p %= N;
        roul %= K;
    }
    for (p = 0; p < N; p++) {
        if (r[p] == 0) {
            cout << p+1 << " ";
        }
    }
    cout << "\n";
}

int main (void) {
    int T, tc;
    cin >> T;
    for (tc = 1; tc <= T; tc++) {
        cin >> N >> K;
        memset(r, 0, sizeof(int)*N);
        josephus();
    }
    return 0;
}
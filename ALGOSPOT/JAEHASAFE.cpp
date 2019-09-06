#include <iostream>

using namespace std;

string origin;
int len;

int shiftHandle (int dir, string &ans) {
    int i, j;
    string _origin = origin + origin;
    if (dir == 1) {
        for (i = 0; i < len; i++) {
            j = 0;
            for ( ; j < len; j++) {
                if (_origin[i+j] != ans[j]) break;
            }
            if (j == len) break;
        }
    } else {
        for (i = 0; i < len; i++) {
            j = 0;
            for ( ; j < len; j++) {
                if (_origin[len-i+j] != ans[j]) break;
            }
            if (j == len) break;
        }
    }
    origin = ans;
    return i;
}

int main (void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int T, tc, N, i, res;
    string ip;
    cin >> T;
    for (tc = 1; tc <= T; tc++) {
        res = 0;
        cin >> N >> origin;
        len = origin.length();
        for (i = 0; i < N; i++) {
            cin >> ip;
            res += shiftHandle (i % 2, ip);
            #ifdef PPRINT
            cout << res << "\n";
            #endif
        }
        cout << res << "\n";
    }
    return 0;
}
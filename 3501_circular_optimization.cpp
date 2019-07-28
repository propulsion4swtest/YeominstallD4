#include <bits/stdc++.h>

using namespace std;

int main (void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int T, tc, p, q, clen, k;
    string s;
    map <int, int> cache;
    cin >> T;
    for (tc = 1; tc <= T; tc++) {
        cache.clear();
        cin >> p >> q;
        k = 0; clen = 0;
        s = to_string((int)(p/q));
        if (p % q != 0) {
            s += ".";
        }
        p = (p % q) * 10;
        while (p != 0) {
            cache[p] = k++;
            s += to_string ((int)(p/q));
            p = (p % q) * 10;

            if (cache.find(p) != cache.end()) {
                clen = k - cache[p];
                s.insert (s.size() - clen, "(");
                s += ")";
                break;
            }
        }
        cout << "#" << tc << " " << s << "\n";
    }
}
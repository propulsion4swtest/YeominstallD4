#include <iostream>
#include <cstring>

using namespace std;

int N;
int cache[101];

int tiling (int pc) {
    if (pc < 3) return pc;
    else if (cache[pc] == -1) {
        cache[pc] = ((tiling(pc-1) + tiling(pc-2)) % 1000000007);
    }
    return cache[pc];
}

int main (void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int T, tc, res;
    memset(cache, -1, sizeof(cache));
    cache[1] = 1;
    cache[2] = 2;
    cin >> T;
    for (tc = 1; tc <= T; tc++) {
        cin >> N;
        res = tiling(N);
        cout << res << "\n";
    }
    return 0;
}
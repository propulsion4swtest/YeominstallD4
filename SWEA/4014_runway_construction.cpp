/**
 * swea 4014
 */
#include <bits/stdc++.h>

using namespace std;

int field[20][20];
int N, X;

bool isRunway (int idx, bool isCol) {
    int prev, curr, dx, dy;
    if (isCol) {
        dx = idx;
        dy = 0;
        prev = field[dy++][dx];
    } else {
        dx = 0;
        dy = idx;
        prev = field[dy][dx++];
    }
    int ground = 1, b = 0;
    bool isDesc = false;
    while (dx != N && dy != N) {
        curr = field[dy][dx];
        b = curr - prev;
        if (b < -1 || b > 1) return false;
        if (b == 0) {
            ground++;
            if (isDesc && ground >= X) {
                ground = 0;
                isDesc = false;
            }
        } else {
            if (b == 1 && ground < X) return false;
            if (b == -1 && isDesc) return false;
            if (b == -1) isDesc = true;
            ground = 1;
        }
        prev = curr;
        if (isCol) dy++;
        else dx++;
    }
    if (isDesc) return false;
    return true;
}

int main (void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int T, tc, i, j, cnt;
    cin >> T;
    for (tc = 1; tc <= T; ++tc) {
        cnt = 0;
        cin >> N >> X;
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                cin >> field[i][j];
            }
        }
        for (i = 0; i < N; i++) {
            if (isRunway(i, 1)) cnt++;
            if (isRunway(i, 0)) cnt++;
        }
        cout << "#" << tc << " " << cnt << "\n";
    }
    return 0;
}
/**
 * swea 1767
 */
#include <bits/stdc++.h>

using namespace std;

int N, k, l;
bool PCB[12][12];
bool copied[12][12];
int dx[5] = {0, 1, 0, -1, 0};
int dy[5] = {-1, 0, 1, 0, 0};

void initPCB () {
    memcpy(copied, PCB, sizeof(PCB));
}

int dfs (int px, int py) {

}

int main (void) {
    int T, tc, i, j;
    cin >> T;
    for (tc = 1; tc <= T; tc++) {
        cin >> N;
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                cin >> PCB[i][j];
            }
        }
        initPCB();
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                if (PCB[i][j] == 1) {
                    dfs
                }
            }
        }

    }
}
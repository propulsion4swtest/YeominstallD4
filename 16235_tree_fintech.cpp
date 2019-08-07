#include <bits/stdc++.h>

#define __OOB__(x, y)   (x < 0 || x >= N || y < 0 || y >= N)

using namespace std;

typedef struct cell {
    int cnt;
    int trees[1000];
    int nfert;
} _cell;

int N, M, K;
int fertility[10][10];
int soil[10][10];
cell ground[10][10];

void initFertility (void) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            fertility[i][j] = 5;
        }
    }
}

void sortTrees (void) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            sort(ground[i][j].trees, ground[i][j].trees+ground[i][j].cnt, greater<int>());
        }
    }
}

void spring() {
    int i, j, k;
    int fert, cnt_diff;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cnt_diff = 0;
            for (k = ground[i][j].cnt-1; k >= 0; k--) {
                fert = fertility[i][j] - ground[i][j].trees[k];
                if (fert < 0) {
                    ground[i][j].nfert += (int)(ground[i][j].trees[k] / 2);
                    ground[i][j].trees[k] = 0;
                    cnt_diff++;
                } else {
                    fertility[i][j] -= ground[i][j].trees[k];
                    ground[i][j].trees[k]++;
                }
            }
            sort(ground[i][j].trees, ground[i][j].trees+ground[i][j].cnt, greater<int>());
            ground[i][j].cnt -= cnt_diff;
        }
    }
}

void summer() {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            fertility[i][j] += ground[i][j].nfert;
            ground[i][j].nfert = 0;
        }
    }
}

void autumn() {
    int i, j, k, near, nx, ny;
    int dir[8][2] = {-1, -1, 0, -1, 1, -1, -1, 0, 1, 0, -1, 1, 0, 1, 1, 1};
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            for (k = 0; k < 1000; k++) {
                if (ground[i][j].trees[k] != 0 && ground[i][j].trees[k] % 5 == 0) {
                    for (near = 0; near < 8; near++) {
                        ny = i + dir[near][0];
                        nx = j + dir[near][1];
                        if (__OOB__(nx, ny)) continue;
                        ground[ny][nx].trees[ground[ny][nx].cnt++] = 1;
                    }
                }
            }
        }
    }
}

void winter() {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            fertility[i][j] += soil[i][j];
        }
    }
}

void yearly() {
    spring();
    summer();
    autumn();
    winter();
}

int countTrees (void) {
    int i, j, cnt = 0;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cnt += ground[i][j].cnt;
        }
    }
    return cnt;
}

void listTrees (void) {
    int i, j, k;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            for (k = 0; k < ground[i][j].cnt; k++) {
                cout << i << "," << j << "," << ground[i][j].trees[k] << "\n";
            }
        }
    }
}

int main (void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int trees, i, j, age, r, c, cnt;
    cin >> N >> M >> K;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cin >> soil[i][j];
        }
    }
    for (i = 0; i < M; i++) {
        cin >> r >> c >> age;
        ground[r-1][c-1].cnt = 0;
        ground[r-1][c-1].trees[ground[r-1][c-1].cnt] = age;
        ground[r-1][c-1].nfert = 0;
        ground[r-1][c-1].cnt++;
    }
    sortTrees();
    initFertility();
    for (i = 0; i < K; i++) {
        yearly();
        cout << "==========\n";
        listTrees();
        cout << "==========\n";
    }
    cnt = countTrees();
    cout << cnt << "\n";
    return 0;
}

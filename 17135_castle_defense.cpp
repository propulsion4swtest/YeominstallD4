#include <bits/stdc++.h>
#define __OOB__(x, y)   (x < 0 || x >= M || y < 0 || y >= N)

using namespace std;

int N, M, D;
bool field[15][15];
bool t_field[15][15];
int targets[3][2];
int rear;
int archery[15] = {0};
int enemy, t_enemy;

void setField (void) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            t_field[i][j] = field[i][j];
        }
    }
}

int distance (int x1, int y1, int x2, int y2) {
    return abs(x1-x2) + abs(y1-y2);
}

void shotRange (int px, int py) {
    int i, j, k, diff, dy;
    diff = D - 1;
    for (i = 0; i <= diff; i++) {
        for (j = -i; j <= i; j++) {
            dy = i - abs(j);
            if (__OOB__(px+j, py-dy)) continue;
            if (t_field[py-dy][px+j]) {
                targets[rear][0] = px+j;
                targets[rear][1] = py-dy;
                rear++;
                return;
            }
        }
    }
}

void eraseFirst (int py) {
    for (int k = 0; k < M; k++) {
        if (t_field[py][k]) {
            t_enemy--;
            t_field[py][k] = 0;
        }
    }
}

int shotArrow (void) {
    int sc = 0, i, j;
    for (i = N-1; i >= 0; i--) {
        rear = 0;
        for (j = 0; j < M; j++) {
            if (archery[j] == 1) {
                shotRange(j, i);
            }
        }
        for (j = 0; j < rear; j++) {
            if (t_field[targets[j][1]][targets[j][0]]) {
                sc++;
                t_field[targets[j][1]][targets[j][0]] = 0;
                t_enemy--;
            }
        }
        eraseFirst(i);
        if (t_enemy == 0) break;
    }
    return sc;
}

void printCase (void) {
    for (int i = 0; i < M; i++) {
        cout << archery[i] << " ";
    }
    cout << "\n";
}

int main (void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int max_score = -1, score, i, j;
    cin >> N >> M >> D;
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            cin >> field[i][j];
            if (field[i][j] == 1) enemy++;
        }
    }
    for (i = 0; i < 3; i++) {
        archery[M-1-i] = 1;
    }
    do {
        setField();
        t_enemy = enemy;
        score = shotArrow();
        max_score = (max_score < score) ? score : max_score;
    } while (next_permutation(archery, archery+M));
    cout << max_score << "\n";
    return 0;
}
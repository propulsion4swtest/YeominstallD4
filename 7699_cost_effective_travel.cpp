/**
 * swea 7699
 */
#include <bits/stdc++.h>
#define MAX(a,b)    (a > b) ? a : b;

using namespace std;

int R, C, k, l, deepest;
int dx[4] = {0, 0, -1, 1};  // UDLR
int dy[4] = {-1, 1, 0, 0};
char isle[21][21];
bool visited[26];

void printVisited (void) {
    for (k = 0; k < 26; k++) {
        if (visited[k]) cout << (char)('A'+k);
    }
    cout << "\n";
}

void resetVisited (void) {
    deepest = -1;
    for (k = 0; k < 26; k++) visited[k] = false;
}

void printIsle (void) {
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            cout << isle[i][j];
        }
        cout << "\n";
    }
}

bool isBoundary (int x, int y) {
    if (x < 0 || x >= C || y < 0 || y >= R) return false;
    return true;
}

int dfsPath (int x, int y) {
    int stk[30][2];
    int top = -1, ctop;
    bool route[21][21][4] = {0,};
    int bx, by, cx, cy;
    stk[++top][0] = x; stk[top][1] = y;
    visited[isle[y][x] - 'A'] = true;
    while (top != -1) {
        ctop = top;
        bx = stk[top][0];   by = stk[top][1];
        for (k = 0; k < 4; k++) {
            cx = bx + dx[k];    cy = by + dy[k];
            if (!isBoundary(cx, cy) || route[by][bx][k] || visited[isle[cy][cx] - 'A']) continue;
            stk[++top][0] = cx;
            stk[top][1] = cy;
            route[by][bx][k] = true;
            visited[isle[cy][cx] - 'A'] = true;
            break;
        }
        if (ctop == top) {
            deepest = MAX(top+1, deepest);
            if (deepest == 26) return deepest;
            for (k = 0; k < 4; k++) {
                route[by][bx][k] = false;
            }
            visited[isle[stk[top][1]][stk[top][0]] - 'A'] = false;
            top--;
        }
    }
    return deepest;
}

int main (void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int T, tc, i, j;
    std::string row;
    cin >> T;
    for (tc = 1; tc <= T; ++tc) {
        cin >> R >> C;
        for (i = 0; i < R; i++) {
            cin >> isle[i];
        }
        resetVisited();
        std::cout << "#" << tc << " " << dfsPath(0, 0) << "\n";
    }
    return 0;
}
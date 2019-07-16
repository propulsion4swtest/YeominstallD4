/**
 * swea 2814
 */
#include <bits/stdc++.h>

using namespace std;

bool path[11][11];
int N, M, j, k;

void clearPath (void) {
    for (j = 0; j < 11; j++) {
        for (k = 0; k < 11; k++) {
            path[j][k] = false;
        }
    }
}

int makeDfsPath (int start) {
    int max_len = -1, from;
    stack<int> visited;
    visited.push(start);
    while (!visited.empty()) {
        from = visited.top();
        for (j = 0; j < N; j++) {
            if (path[from][j] || path[j][from]) {
                visited.push(j);
                break;
            }
        }
        if (from == visited.top()) {
            max_len = (max_len < visited.size()) ? visited.size() : max_len;
            visited.pop();
        }
    }
    return max_len;
}

int main (void) {
    int T, tc, i, nd1, nd2, len, maxlength = -1;
    cin >> T;
    for (tc = 1; tc <= T; tc++) {
        cin >> N >> M;
        clearPath();
        for (i = 0; i < M; i++) {
            cin >> nd1 >> nd2;
            path[nd1][nd2] = true;
        }
        for (i = 1; i <= N; i++) {
            len = makeDfsPath(i);
            maxlength = (maxlength < len) ? len : maxlength;
        }
        cout << "#" << tc << " " << maxlength << "\n";
    }
}
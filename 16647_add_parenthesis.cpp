/**
 * swea 16647
 */
#include <bits/stdc++.h>

using namespace std;

int N, res;
string expr;
int mid[20];
int cmb[9];

int calc (int a, int b, char opt) {
    switch (opt) {
        case '+':
            return a+b;
        case '-':
            return a-b;
        case '*':
            return a*b;
        default:
            return (1<<31);
    }
    return (1<<31);
}

int oper (int idx) {
    char opt = expr[idx+1];
    int a, b;
    a = expr[idx] - '0';
    b = expr[idx+2] - '0';
    return calc (a, b, opt);
}

void setComb (int r) {
    int i;
    for (i = 0; i < N/2-r; i++) cmb[i] = 0;
    for ( ; i < N/2; i++) cmb[i] = 1;
}

bool isValid (void) {
    int i;
    for (i = 0; i < N/2-1; i++) {
        if (cmb[i] + cmb[i+1] == 2) return false;
    }
    return true;
}

int main (void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    long max_res = LONG_MAX, i, j, k;
    cout << sizeof(int) << "\n";
    int n_num, n_opt;
    cin >> N >> expr;
    if (N == 1) {
        cout << expr << "\n";
        return 0;
    } else if (N == 3) {
        cout << oper(0) << "\n";
        return 0;
    }
    n_num = N / 2 + 1;
    n_opt = N - n_num;
    for (i = 0; i < n_opt; i++) {
        mid[i] = oper(i*2);
    }
    for (i = 0; i < n_opt; i++) {
        setComb(i);
        do {
            if (!isValid()) continue;
            res = 0;
            for (j = 0; j < n_num; j++) {
                if (cmb[j] == 1) {
                    if (j == 0) {
                        res = oper(0);
                    } else {
                        res = calc(res, mid[j], expr[j*2-1]);
                    }
                    j++;
                } else {
                    if (j == 0) {
                        res = expr[0] - '0';
                    } else {
                        res = calc(res, expr[j*2]-'0', expr[j*2-1]);
                    }
                }
            }
            // for (k = 0; k < n_num; k++) {
            //     cout << cmb[k] << " ";
            // }
            // cout << ": ";
            // cout << res << "\n";
            
            max_res = (max_res < res) ? res : max_res;
        } while (next_permutation(cmb, cmb+(N/2)));
    }
    cout << max_res << "\n";
    return 0;
}
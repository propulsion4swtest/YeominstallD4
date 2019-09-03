#include <iostream>
#include <vector>

using namespace std;

void josephus (int n, int k) {
    int i;
    vector<int> survivors;
    vector<int>::iterator kill;
    survivors.reserve(n);
    for (i = 1; i <= n; ++i) survivors.push_back(i);
    kill = survivors.begin();
    while (n > 2) {
        #ifdef PPRINT
        for (vector<int>::iterator it = survivors.begin(); it != survivors.end(); it++) {
            cout << *it << " ";
        }
        cout << "\n";
        #endif
        kill = survivors.erase(kill);
        --n;
        kill = survivors.begin() + (((kill - survivors.begin()) + k-1) % survivors.size());
    }
    cout << survivors.front() << " " << survivors.back() << "\n";
}

int main (void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int T, tc, N, K;
    cin >> T;
    for (tc = 1; tc <= T; tc++) {
        cin >> N >> K;
        josephus(N, K);
    }
    return 0;
}
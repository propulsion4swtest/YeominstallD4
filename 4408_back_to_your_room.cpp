#include <iostream>

int room_state[200];

void roomSet(void) {
    for (int i = 0; i < 200; i++) {
        room_state[i] = 0;
    }
}

void calcCorridor(int lower, int higher) {
    for (int i = lower; i <= higher; i++) {
        room_state[i]++;
    }
}

int maxCorridor(void) {
    int max = -1;
    for (int i = 0; i < 200; i++) {
        max = (max < room_state[i]) ? room_state[i] : max;
    }
    return max;
}

int main (void) {
    std::cin.tie(0); std::cout.tie(0);
    std::ios_base::sync_with_stdio(0);
    int T;
    std::cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        int N, from, to;
        std::cin >> N;
        roomSet();
        for (int i = 0; i < N; i++) {
            std::cin >> from >> to;
            from = ((from + 1) / 2) - 1;
            to = ((to + 1) / 2) - 1;
            if (from == to) {
                room_state[from]++;
            } else {
                (from < to) ? calcCorridor(from, to) : calcCorridor(to, from);
            }
        }
        std::cout << "#" << tc << " " << maxCorridor() << "\n";
    }
}
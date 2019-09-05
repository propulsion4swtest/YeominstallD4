#include <iostream>
#include <stack>

using namespace std;

bool isMatched (string b) {
    stack<char> s;
    for (string::iterator it = b.begin(); it != b.end(); it++) {
        #ifdef PPRINT
        cout << *it << "\n";
        #endif
        if (!s.empty()) {
            if (*it == ')' && s.top() == '(') {
                s.pop();
            } else if (*it == '}' && s.top() == '{') {
                s.pop();
            } else if (*it == ']' && s.top() == '[') {
                s.pop();
            } else {
                s.push(*it);
            }
        } else {
            s.push(*it);
        }
    }
    #ifdef PPRINT
    cout << s.size() << "\n";
    #endif
    return s.empty();
}

int main (void) {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    int T, tc;
    std::string brackets;
    cin >> T;
    for (tc = 1; tc <= T; tc++) {
        cin >> brackets;
        if (isMatched(brackets)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}
#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T; cin >> T;
    string s;
    while(T--) {
        cin >> s;
        bool ans = true;
        stack<char> st;
        for(char e : s) {
            if(e == '(')
                st.push('(');
            else {
                if(st.empty()) {
                    ans = false;
                    break;
                }
                st.pop();
            }
        }
        if(ans && st.empty())
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
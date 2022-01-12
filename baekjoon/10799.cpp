#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    stack<char> st;
    string s; cin >> s;
    int ans = 0;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(') st.push('(');
        else {
            st.pop();
            if(s[i-1] == '(')
                ans += st.size();
            else
                ans++;
        }
    }
    cout << ans;
}
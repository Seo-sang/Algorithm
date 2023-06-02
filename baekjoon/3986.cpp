#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    int ans = 0;
    while(N--) {
        string str; cin >> str;
        stack<char> st;
        for(char c : str) {
            if(!st.empty() && st.top() == c) st.pop();
            else st.push(c);
        }

        if(st.empty()) ans++;
    }

    cout << ans;
}
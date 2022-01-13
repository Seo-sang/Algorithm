#include <iostream>
#include <stack>

using namespace std;

stack<int> st;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    string str; cin >> str;
    int ans = 0;
    int score;
    for(char c : str) {
        if(c == '(' || c == '[') st.push(c);
        else {
            if(c == ')' ) {
                score = 0;
                while(!st.empty() && st.top() != '(') {
                    if(st.top() == '[') {
                        cout << 0;
                        return 0;
                    }
                    score += st.top();
                    st.pop();
                }
                if(st.empty()) {
                    cout << 0;
                    return 0;
                }
                st.pop();
                if(score == 0)
                    score = 2;
                else
                    score *= 2;

                if(st.empty())
                    ans += score;
                else
                    st.push(score);
            }
            if(c == ']') {
                score = 0;
                while(!st.empty() && st.top() != '[') {
                    if(st.top() == '(') {
                        cout << 0;
                        return 0;
                    }
                    score += st.top();
                    st.pop();
                }
                if(st.empty()) {
                    cout << 0;
                    return 0;
                }
                st.pop();
                if(score == 0)
                    score = 3;
                else
                    score *= 3;
                    
                if(st.empty())
                    ans += score;
                else
                    st.push(score);
            }
        }
    }
    if(st.empty())
        cout << ans;
    else
        cout << 0;
}
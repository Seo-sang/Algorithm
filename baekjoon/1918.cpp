#include <iostream>
#include <stack>

using namespace std;

const int MN = 101;

int main() {
    string s; cin >> s;
    stack<char> st;
    for(char c : s) {
        if(isalpha(c)) cout << c;
        else {
            if(c == '(') st.push('(');
            else if(c == ')') {
                while(st.top() != '(') {
                    cout << st.top();
                    st.pop();
                }
                st.pop();
            }
            else if(c == '+' || c == '-') {
                if(st.empty() || st.top() == '(') st.push(c);
                else {
                    while(!st.empty() && st.top() != '(' ) {
                        cout << st.top();
                        st.pop();
                    }
                    st.push(c);
                }
            }
            else {
                if(st.empty()|| st.top() == '(') st.push(c);
                else if(st.top() == '+' || st.top() == '-') {
                    st.push(c);
                }
                else if(st.top() == '*' || st.top() == '/') {
                    cout << st.top();
                    st.pop();
                    st.push(c);
                }
            }
        }
    }
    while(!st.empty()) {
        cout << st.top();
        st.pop();
    }
}
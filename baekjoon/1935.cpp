#include <iostream>
#include <stack>
#include <map>

using namespace std;
const int MN = 27;
map<char,int> m;

int main() {
    int N; cin >> N;
    stack<double> st;
    string s; cin >> s;
    char alpha = 'A';
    for(int i = 0; i < N; i++) {
        int a; cin >> a;
        m[alpha] = a;
        alpha++;
    }
    int idx = 0;
    for(char c : s) {
        if(isalpha(c)) st.push(m[c]);
        else {
            double b = st.top(); st.pop();
            double a = st.top(); st.pop();
            double rst;
            switch(c) {
                case '*':
                    rst = a * b;
                    break;
                case '/':
                    rst = a / b;
                    break;
                case '+':
                    rst = a + b;
                    break;
                case '-':
                    rst = a - b;
                    break;
            }
            st.push(rst);
        }
    }
    printf("%.2lf", st.top());
}
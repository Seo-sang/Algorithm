#include <bits/stdc++.h>
#define P pair<int,int>
using namespace std;

int N;

void dfs(int n, vector<int> v, vector<char> op, string s) {
    if(n == N) {
        int rst = v.front();
        for(int i = 1; i < v.size(); i++) {
            switch(op[i-1]) {
                case '+':
                    rst += v[i];
                    break;
                case '-':
                    rst -= v[i];
                    break;
            }
        }
        if(rst == 0) cout << s << '\n';
        return;
    }
    
    string tmp = s;
    tmp += ' ';
    int num = v.back();
    v.pop_back();
    v.push_back(num * 10 + (n + 1));
    dfs(n + 1, v, op, tmp + to_string(n + 1));
    v.pop_back();
    v.push_back(num);
    
    tmp = s;
    tmp += '+';
    v.push_back(n + 1);
    op.push_back('+');
    dfs(n + 1, v, op, tmp + to_string(n + 1));
    v.pop_back();
    op.pop_back();
    
    tmp = s;
    tmp += '-';
    v.push_back(n + 1);
    op.push_back('-');
    dfs(n + 1, v, op, tmp + to_string(n + 1));
    v.pop_back();
    op.pop_back();

}

int main() {
    int T; cin >> T;
    while(T--) {
        cin >> N;
        dfs(1, vector<int> (1, 1), vector<char>(), "1");
        cout << '\n';
    }
}
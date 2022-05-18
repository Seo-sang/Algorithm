#include <bits/stdc++.h>

using namespace std;
int A, B, C;
bool vst[201][201][201];
set<int> ans;

void dfs(int a, int b, int c) {
    if(vst[a][b][c]) return;
    vst[a][b][c] = true;
    if(a == 0) ans.insert(c);

    if(a != 0) {
        //b에 따르는 경우
        int gap = min(a, B - b);
        dfs(a - gap, b + gap, c);
        //c에 따르는 경우
        gap = min(a, C - c);
        dfs(a - gap, b, c + gap);
    }

    if(b != 0) {
        //a에 따르는 경우
        int gap = min(A - a, b);
        dfs(a + gap, b - gap, c);
        //c에 따르는 경우
        gap = min(b, C - c);
        dfs(a, b - gap, c + gap);
    }

    if(c != 0) {
        //a에 따르는 경우
        int gap = min(c, A - a);
        dfs(a + gap, b, c - gap);
        //b에 따르는 경우
        gap = min(c, B - b);
        dfs(a, b + gap, c - gap);
    }
}

int main() {
    cin >> A >> B >> C;
    dfs(0, 0, C);
    for(auto it = ans.begin(); it != ans.end(); it++) 
        cout << *it << ' ';
}
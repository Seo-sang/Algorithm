#include <bits/stdc++.h>

using namespace std;
const int MN = 1001;
int cnt[27][MN];

int main() {
    int N, M; cin >> N >> M;
    for(int i = 0; i < N; i++) {
        string str; cin >> str;
        for(int j = 0; j < M; j++)
            cnt[str[j] - 'A'][j]++;
    }
    string ans = "";
    int answer = 0;
    for(int i = 0; i < M; i++) {
        char mnum = 'A';
        for(char c = 'B'; c <= 'Z'; c++)
            if(cnt[c - 'A'][i] > cnt[mnum - 'A'][i])
                mnum = c;

        ans = ans + mnum;
        answer += (N - cnt[mnum - 'A'][i]);
    }
    cout << ans << '\n' << answer;
}
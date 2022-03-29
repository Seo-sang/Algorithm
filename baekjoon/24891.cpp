#include <bits/stdc++.h>

using namespace std;
const int MN = 21;
string arr[MN];
bool vst[MN];
vector<string> ans;
int L, N;

void dfs(int cnt, vector<string> v) {
    if(cnt == L) {
        bool chk = true;
        for(int i = 0; i < L; i++) {
            for(int j = 0; j < L; j++) {
                if(v[i][j] != v[j][i]) {
                    chk = false;
                    break;
                }
            }
            if(!chk) break;
        }
        if(chk)
            ans = v;
        return;
    }
    for(int i = 0; i < N; i++) {
        if(vst[i]) continue;
        vst[i] = true;
        v.push_back(arr[i]);
        dfs(cnt + 1, v);
        if(ans.size() == L) return;
        v.pop_back();
        vst[i] = false;
    }
}

int main() {
    cin >> L >> N;
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    vector<string> v;
    sort(arr, arr + N);
    memset(vst, 0, sizeof(vst));
    for(int i = 0; i < N; i++) {
        v.push_back(arr[i]);
        vst[i] = true;
        dfs(1, v);
        vst[i] = false;
        v.pop_back();
        if(ans.size() == L) break;
    }

    if(ans.size() == 0) cout << "NONE";
    else {
        for(int i = 0;  i < L; i++)
            cout << ans[i] << '\n';
    }
}
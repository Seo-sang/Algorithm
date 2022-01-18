#include <bits/stdc++.h>

using namespace std;

const int MN = 1001;
int pre[MN];
int pos[MN];
int in[MN];

void post(int prestart, int preend, int instart, int inend) {
    if(prestart >= preend || instart >= inend) return;
    int rootidx = pos[pre[prestart]];
    int lsize = rootidx - instart;
    int rsize = inend - rootidx;

    post(prestart + 1, prestart + lsize + 1, instart, rootidx-1);
    post(preend - rsize + 1, preend, rootidx + 1, inend);    
    cout << pre[prestart] << ' ';

}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T; cin >> T;
    while(T--) {
        int N; cin >> N;
        memset(pre, 0, sizeof(pre));
        memset(in, 0, sizeof(in));
        memset(pos, 0, sizeof(pos));
        for(int i = 0; i < N; i++)
            cin >> pre[i];
        for(int i = 0; i < N; i++) {
            cin >> in[i];
            pos[in[i]] = i;
        }
        post(0, N-1, 0, N-1);
        cout << '\n';
    }
}
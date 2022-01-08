#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MN = 100001;
int team[MN];
int want[MN];
bool visit[MN];
int cnt;

int dfs(int n) {
    if(team[n]) return 0;
    if(visit[n]) return n;
    visit[n] = 1;
    int ret = dfs(want[n]);
    if(ret) {
        if(ret == n) ret = 0;
        team[n] = 1;
    }
    else {
        team[n] = -1;
        cnt++;
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T; cin >> T;
    while(T--) {
        int N; cin >> N;
        cnt = 0;
        memset(team, 0, sizeof(team));
        memset(want, 0, sizeof(want));
        memset(visit, 0, sizeof(visit));
        for(int i = 1; i <= N; i++) 
            cin >> want[i];
        
        for(int i = 1; i <= N; i++) {
            if(!team[i]) {
                visit[i] = true;
                if(dfs(want[i]) != 0) {
                    team[i] = 1;
                }
                else {
                    team[i] = -1;
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }
}
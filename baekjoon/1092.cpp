#include <bits/stdc++.h>
#define P pair<int,int>
using namespace std;

const int MN = 51;
vector<int> limit;
map<int, int> box;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M; cin >> N;
    int a;
    for(int i = 0; i < N; i++) {
        cin >> a;
        limit.push_back(a);
    }

    cin >> M;
    for(int i = 0; i < M; i++) {
        cin >> a;
        box[a]++;
    }
    int ans = 0;

    while(!box.empty()) {
        bool chk = false;
        ans++;
        for(int e : limit) {
            if(box.empty()) break;
            auto it = box.upper_bound(e);
            if(it != box.begin()) {
                it--;
                it->second--;
                if(it->second == 0) box.erase(it);
                chk = true;
            }
        }

        if(!chk) break;
    }
    if(box.empty()) cout << ans;
    else cout << -1;

}
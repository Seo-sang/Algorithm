#include <iostream>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;

struct pos {
    int x, y;
};

const int MN = 101;
pos conv[MN];
bool visit[MN];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T; cin >> T;
    while(T--) {
        memset(conv, 0, sizeof(conv));
        memset(visit, 0, sizeof(visit));
        int N; cin >> N;
        pos start; cin >> start.x >> start.y;
        for(int i = 0; i < N; i++)
            cin >> conv[i].x >> conv[i].y;
        pos dest; cin >> dest.x >> dest.y;

        queue<pos> q;
        bool rst = false;
        q.push(start);
        while(!q.empty()) {
            pos now = q.front(); q.pop();
            int dist = abs(now.x - dest.x) + abs(now.y - dest.y);
            if(dist <= 1000) {
                rst = true;
                break;
            }
            for(int i = 0; i < N; i++) {
                if(visit[i]) continue;
                int d = abs(conv[i].x - now.x) + abs(conv[i].y - now.y);
                if(d <= 1000) {
                    visit[i] = true;
                    q.push(conv[i]);
                }
            }
        }

        if(rst)
            cout << "happy\n";
        else
            cout << "sad\n";
    }
}
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
int dept, dest;

struct edge {
    int num;
    string str;
};

const int MN = 10000;
int visit[10000];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T; cin >> T;
    while(T--) {
        cin >> dept >> dest;
        if(dept == dest) {
            cout << '\n';
            continue;
        }
        memset(visit, 0, sizeof(visit));
        visit[dept] = true;
        queue<edge> q;
        q.push({dept, ""});
        bool chk = false;
        while(!q.empty() && !chk) {
            edge now = q.front(); q.pop();
            //D 명령어
            int nxt = now.num * 2;
            nxt %= MN;
            if(nxt == dest) {
                cout << now.str + 'D' <<'\n';
                chk = true;
                continue;
            }
            if(!visit[nxt]) {
                visit[nxt] = true;
                q.push({nxt, now.str + 'D'});
            }
            //S 명령어
            nxt = now.num - 1;
            if(nxt < 0) nxt = 9999;
            if(nxt == dest) {
                cout << now.str + 'S' <<'\n';
                chk = true;
                continue;
            }
            if(!visit[nxt]) {
                visit[nxt] = true;
                q.push({nxt, now.str + 'S'});
            }
            //L 명령어
            nxt = now.num * 10;
            nxt += (now.num / 1000);
            nxt %= MN;
            if(nxt == dest) {
                cout << now.str + 'L' <<'\n';
                chk = true;
                continue;
            }
            if(!visit[nxt]) {
                visit[nxt] = true;
                q.push({nxt, now.str + 'L'});
            }
            //R 명령어
            int d = now.num % 10;
            nxt = now.num / 10;
            nxt += d * 1000;
            if(nxt == dest) {
                cout << now.str + 'R' <<'\n';
                chk = true;
                continue;
            }
            if(!visit[nxt]) {
                visit[nxt] = true;
                q.push({nxt, now.str + 'R'});
            }
        }
    }
}
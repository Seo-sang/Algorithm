#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
int dept, dest;

struct edge {
    int d1, d2, d3, d4;
    string str;
};

int visit[10000];

int sum(int d1, int d2, int d3, int d4) {
    return (((d1 * 10) + d2) * 10  + d3) * 10 + d4;
}

void modify(int &d1, int &d2, int &d3, int &d4) {
    if(d4 > 9) {
        d4 -= 10;
        d3++;
    }
    if(d3 > 9) {
        d3 -= 10;
        d2++;
    }
    if(d2 > 9) {
        d2 -= 10;
        d1++;
    }
    d1 %= 10;
}


int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T; cin >> T;
    while(T--) {
        cin >> dept >> dest;
        if(dept == dest) {
            cout << '\n';
            continue;
        }
        int d1, d2, d3, d4;
        d1 = d2 = d3 = d4 = 0;
        d4 = dept % 10;
        dept /= 10;
        d3 = dept % 10;
        dept /= 10;
        d2 = dept % 10;
        dept /= 10;
        d1 = dept % 10;
        memset(visit, 0, sizeof(visit));
        visit[dept] = true;
        queue<edge> q;
        q.push({d1, d2, d3, d4, ""});
        while(!q.empty()) {
            edge now = q.front(); q.pop();
            int n1, n2, n3, n4;
            //D 명령어
            n1 = now.d1 * 2;
            n2 = now.d2 * 2;
            n3 = now.d3 * 2;
            n4 = now.d4 * 2;
            modify(n1, n2, n3, n4);
            int rst = sum(n1, n2, n3, n4);
            if(rst == dest) {
                cout << now.str + 'D' << '\n';
                break;
            }
            if(!visit[rst]) {
                visit[rst] = true;
                q.push({n1, n2, n3, n4, now.str + 'D'});
            }
            //S 명령어
            if(sum(now.d1, now.d2, now.d3, now.d4) == 0) n1 = n2 = n3 = n4 = 9;
            else {
                n4 = now.d4 - 1;
                n3 = now.d3;
                n2 = now.d2;
                n1 = now.d1;
                if(n4 < 0) n4 += 10, n3--;
                if(n3 < 0) n3 += 10, n2--;
                if(n2 < 0) n2 += 10, n1--;
            }
            rst = sum(n1, n2, n3, n4);
            if(rst == dest) {
                cout << now.str + 'S' << '\n';
                break;
            }
            if(!visit[rst]) {
                visit[rst] = true;
                q.push({n1, n2, n3, n4, now.str + 'S'});
            }
            
            //L 명령어
            n1 = now.d2;
            n2 = now.d3;
            n3 = now.d4;
            n4 = now.d1;
            rst = sum(n1, n2, n3, n4);
            if(rst == dest) {
                cout << now.str + 'L' << '\n';
                break;
            }
            if(!visit[rst]) {
                visit[rst] = true;
                q.push({n1, n2, n3, n4, now.str + 'L'});
            }

            //R 명령어
            n1 = now.d4;
            n2 = now.d1;
            n3 = now.d2;
            n4 = now.d3;
            rst = sum(n1, n2, n3, n4);
            if(rst == dest) {
                cout << now.str + 'R' << '\n';
                break;
            }
            if(!visit[rst]) {
                visit[rst] = true;
                q.push({n1, n2, n3, n4, now.str + 'R'});
            }
        }
    }
}
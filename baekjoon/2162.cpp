#include <bits/stdc++.h>
#define pii pair<int,int>

using namespace std;

const int MN = 3001;

struct node {
    int x1, y1, x2, y2;
};

vector<node> arr(MN);
int p[MN];
map<int, int> m;

void init(int n) {
    for(int i = 1; i <= n; i++) p[i] = i;
}

int find(int n) {
    if(p[n] == n) return n;
    return p[n] = find(p[n]);
}

int transform(int n) {
    if(n > 0) return 1;
    else if(n < 0) return -1;
    else return 0;
}

bool CCW(node a, node b) {
    int ABC = (a.x2 - a.x1) * (b.y1 - a.y1) - (b.x1 - a.x1) * (a.y2 - a.y1);
    int ABD = (a.x2 - a.x1) * (b.y2 - a.y1) - (b.x2 - a.x1) * (a.y2 - a.y1);
    int CDA = (b.x2 - b.x1) * (a.y1 - b.y1) - (a.x1 - b.x1) * (b.y2 - b.y1);
    int CDB = (b.x2 - b.x1) * (a.y2 - b.y1) - (a.x2 - b.x1) * (b.y2 - b.y1);
    ABC = transform(ABC);
    ABD = transform(ABD);
    CDA = transform(CDA);
    CDB = transform(CDB);
    if(ABC == 0) {
        if(min(a.x1, a.x2) <= b.x1 && b.x1 <= max(a.x1, a.x2) && min(a.y1, a.y2) <= b.y1 && b.y1 <= max(a.y1, a.y2)) return true;
    }
    if(ABD == 0) {
        if(min(a.x1, a.x2) <= b.x2 && b.x2 <= max(a.x1, a.x2) && min(a.y1, a.y2) <= b.y2 && b.y2 <= max(a.y1, a.y2)) return true;
    }
    if(CDA == 0) {
        if(min(b.x1, b.x2) <= a.x1 && a.x1 <= max(b.x1, b.x2) && min(b.y1, b.y2) <= a.y1 && a.y1 <= max(b.y1, b.y2)) return true;
    }
    if(CDB == 0) {
        if(min(b.x1, b.x2) <= a.x2 && a.x2 <= max(b.x1, b.x2) && min(b.y1, b.y2) <= a.y2 && a.y2 <= max(b.y1, b.y2)) return true;
    }
    if(ABC * ABD < 0 && CDA * CDB < 0) return true;
    else return false;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);

    int N; cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> arr[i].x1 >> arr[i].y1 >> arr[i].x2 >> arr[i].y2;
    }

    init(N);

    for(int i = 1; i < N; i++) {
        for(int j = i + 1; j <= N; j++) {
            int pi = find(i);
            int pj = find(j);
            if(pi == pj) continue;
            if(CCW(arr[i], arr[j])) {
                p[pi] = pj;
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= N; i++) {
        int pi = find(i);
        ans = max(ans, ++m[pi]);
    }

    cout << m.size() << '\n' << ans;
}
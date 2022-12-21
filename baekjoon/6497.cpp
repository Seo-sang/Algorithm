#include <bits/stdc++.h>
#define P pair<int,int>

using namespace std;

const int MN = 200001;
struct node {
    int x, y, z;
    node(int x, int y, int z) : x(x), y(y), z(z) {}
};
vector<node> arr;
int p[MN];

bool cmp(node a, node b) {
    return a.z < b.z;
}

void init(int n) {
    for(int i = 0; i < n; i++) p[i] = i;
}

int find(int n) {
    if(p[n] == n) return n;
    return p[n] = find(p[n]);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int M, N;
    while(true) {
        cin >> M >> N;
        if(M == 0 && N == 0) break;
        int ans = 0, sum = 0;
        arr.clear();
        init(M);
        while(N--) {
            int x, y, z; cin >> x >> y >> z;
            arr.push_back(node(x, y, z));
            sum += z;
        }
        sort(arr.begin(), arr.end(), cmp);
        for(node e : arr) {
            int px = find(e.x);
            int py = find(e.y);
            if(px == py) continue;
            p[px] = py;
            ans += e.z;
        }
        cout << sum - ans << '\n';
    }
}
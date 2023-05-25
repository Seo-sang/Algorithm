#include <bits/stdc++.h>
#define pii pair<int,int>
#define ll long long

using namespace std;

const int MN = 75001;
vector<pii> q;
vector<int> idx;
ll seg[MN * 4];

void update(int node, int left, int right, int pos) {
    if(pos < left || right < pos) return;
    if(left == right) {
        seg[node]++;
        return;
    }
    int mid = (left + right) / 2;

    update(node * 2, left ,mid, pos);
    update(node * 2 + 1, mid + 1, right, pos);

    seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

ll query(int node, int left, int right, int start, int end) {
    if(end < left || right < start) return 0;
    if(start <= left && right <= end) return seg[node];
    int mid = (left + right) / 2;
    return query(node * 2, left, mid, start, end) + query(node * 2 + 1, mid + 1, right, start, end);
}

bool cmp(pii a, pii b) {
    if(a.first == b.first) return a.second > b.second;
    else return a.first < b.first;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T; cin >> T;

    while(T--) {
        //initialization
        idx.clear();
        q.clear();
        memset(seg, 0, sizeof(seg));

        //input stream
        int N; cin >> N;
        int x, y;
        for(int i = 0; i < N; i++) {
            cin >> x >> y;
            q.push_back(pii(x, y));
            idx.push_back(y);
        }

        //sort
        sort(idx.begin(), idx.end());
        sort(q.begin(), q.end(), cmp);

        //deduplication
        idx.erase(unique(idx.begin(), idx.end()), idx.end());

        ll ans = 0;
        for(int i = 0; i < q.size(); i++) {
            //get position
            int pos = lower_bound(idx.begin(), idx.end(), q[i].second) - idx.begin();
            //count
            ans += query(1, 0, N - 1, pos, N - 1);
            //update
            update(1, 0, N - 1, pos);
        }
        cout << ans << '\n';
    }
}
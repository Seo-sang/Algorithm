#include <iostream>
using namespace std;
#define ll long long
#define MN 1010101

ll seg[MN*4];
ll lazy[MN* 4];
ll arr[MN];

ll init(int node, int start, int end) {
    int mid = (start + end) / 2;
    if(start == end) return seg[node] = arr[start];
    else return seg[node] = init(node * 2, start, mid) + init(node * 2 + 1, mid + 1, end);
}

void update_lazy(int node, int start, int end) {
    if(lazy[node]) {
        seg[node] += (end - start + 1) * lazy[node];

        //리프노드가 아니면
        if(start != end) {
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0;
    }
}

void update(int node, int start, int end, int left, int right, ll value) {
    update_lazy(node, start, end);
    if(left > end || right < start) return;
    //전부 범위에 있는 경우
    if(left <= start && end <= right) {
        seg[node] += ((end - start + 1) * value);
        
        //리프노드가 아니면
        if(start != end) {
            lazy[node * 2] += value;
            lazy[node * 2 + 1] += value;
        }
        return;
    }
    int mid = (start + end) / 2;
    update(node * 2, start, mid, left, right, value);
    update(node * 2 + 1, mid + 1, end, left, right, value);

    seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

ll query(int node, int start, int end, int left, int right) {
    update_lazy(node, start, end);
    if(end < left || right < start) return 0;
    if(left <= start && right >= end) return seg[node];
    int mid = (start + end) / 2;
    return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M, K; cin >> N >> M >> K;

    for(int i = 0; i < N; i++)
        cin >> arr[i];

    init(1, 0, N - 1);

    M += K;
    while(M--) {
        long long a, b, c, d; cin >> a;
        if(a == 1) {
            cin >> b >>c >> d;
            update(1, 0, N-1, b - 1, c - 1, d);
        }
        else {
            cin >> b >> c;
            cout << query(1, 0, N-1, b - 1, c - 1) << '\n';
        }
    }

    return 0;
}
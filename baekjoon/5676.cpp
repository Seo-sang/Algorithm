#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MN = 100001;
int seg[MN * 3];

int update(int node, int start, int end, int pos, int value) {
    if(start > pos || end < pos) return seg[node];
    if(start == end) return seg[node] = value;
    int mid = (start + end) / 2;
    return seg[node] = update(node * 2, start, mid, pos, value) * update(node * 2 + 1, mid + 1, end, pos, value);
}

int query(int node, int start, int end, int left, int right) {
    if(end < left || right < start) return 1;
    if(left <= start && end <= right) return seg[node];
    int mid = (start + end) / 2;
    return query(node * 2, start, mid, left, right) * query(node * 2 + 1, mid + 1, end, left, right);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, K;
    fill(seg, seg + (MN * 3 + 1), 1);
    while(cin >> N >> K) {
        for(int i = 0; i < N; i++) {
            int a; cin >> a;
            if(a > 0) a = 1;
            else if(a < 0) a = -1;
            else a = 0;
            update(1, 0, N-1, i, a);
        }
        while(K--) {
            char c; cin >> c;
            int a, b; cin >> a >> b;
            int rst;
            switch(c) {
                case 'C':
                if(b > 0) b = 1;
                else if(b < 0) b = -1;
                else b = 0;
                    update(1, 0, N - 1, a - 1, b);
                    break;
                case 'P':
                    rst = query(1, 0, N - 1, a - 1, b - 1);
                    if(rst > 0)
                        cout << '+';
                    else if(rst < 0)
                        cout << '-';
                    else
                        cout <<  0;
                    break;
            }
        }
        cout << '\n';
    }
}
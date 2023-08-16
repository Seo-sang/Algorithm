#include <bits/stdc++.h>

using namespace std;

const int MN = 50001;
const int INF = 1e9;
int arr[MN];
int T[MN * 4], S[MN * 4];

void init(int node, int left, int right) {
    if(left == right) {
        T[node] = arr[left];
        S[node] = arr[left];
        return;
    }
    int mid = (left + right) >> 1;
    init(node * 2, left, mid);
    init((node * 2) + 1 , mid + 1, right);

    T[node] = max(T[node * 2], T[(node << 1) + 1]);
    S[node] = min(S[node * 2], S[(node << 1) + 1]);
}

int queryS(int node, int left, int right, int start, int end) {
    if(right < start || end < left) return INF;
    if(start <= left && right <= end) return S[node];
    int mid = (left + right) >> 1;
    return min(queryS((node << 1), left, mid, start, end), queryS((node << 1) + 1, mid + 1, right, start, end));
}

int queryT(int node, int left, int right, int start, int end) {
    if(right < start || end < left) return 0;
    if(start <= left && right <= end) return T[node];
    int mid = (left + right) >> 1;
    return max(queryT(node << 1, left, mid, start, end), queryT((node << 1) + 1, mid + 1, right, start, end));
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, Q; cin >> N >> Q;
    for(int i = 0; i < N; i++) cin >> arr[i];
    fill(&T[0], &T[MN * 4], 0);
    fill(&S[0], &S[MN * 4], INF);
    init(1, 0, N - 1);
    while(Q--) {
        int a, b; cin >> a >> b;
        a--, b--;
        int tmpT = queryT(1, 0, N - 1, a, b);
        int tmpS = queryS(1, 0, N - 1, a, b);
        cout << tmpT - tmpS << '\n';
    }
}
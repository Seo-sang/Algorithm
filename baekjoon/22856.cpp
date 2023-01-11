#include <bits/stdc++.h>
#define P pair<int,int>

using namespace std;
const int MN = 100001;
P tree[MN];
int ans = 0, cnt = 0, answer;
int N;

void search(int now) {
    int left = tree[now].first, right = tree[now].second;
    if(left != -1) {
        ans++;
        search(left);
    }
    cnt++;
    if(right != -1) {
        ans++;
        search(right);
    }
    if(cnt == N) {
        answer = ans;
        return;
    }
    ans++;
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        int a, b, c; cin >> a >> b >> c;
        tree[a] = make_pair(b, c);
    }
    search(1);
    cout << answer;
}
#include <bits/stdc++.h>

using namespace std;
const int MN = 123457;
int arr[MN], par[MN], child[MN];
queue<int> q;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    for(int i = 2; i <= N; i++) {
        char t;
        int a, p;
        cin >> t >> a >> p;
        if(t == 'W') arr[i] = -a;
        else arr[i] = a;
        par[i] = p;
        child[p]++;
    }
    for(int i = 1; i <= N; i++) {
        if(child[i] == 0)
            q.push(i);
    }

    while(!q.empty()) {
        int now = q.front(); q.pop();
        int parent = par[now];
        if(arr[now] > 0)
            arr[parent] += arr[now];
        child[parent]--;
        if(child[parent] == 0)
            q.push(parent);
    }

    cout << arr[1];
}
#include <bits/stdc++.h>
#define P pair<int,int>

using namespace std;

const int MN = 200001;
int bead[MN];
P tree[MN];

int dfs(int now) {
    int left = tree[now].first, right = tree[now].second;
    int ret = now;
    //자식이 없는 경우
    if(left == 0 && right == 0) {
        bead[now]++;
        return ret;
    }
    else if(left != 0) { //자식 노드가 한개인 경우
        ret = dfs(left);
        bead[now] = bead[left] + bead[right];
        return ret;
    }
    else if(right != 0) {
        ret = dfs(right);
        bead[now] = bead[left] + bead[right];
        return ret;
    }
    else {//자식 노드가 2개인 경우
        if(bead[left] <= bead[right]) {
            ret = dfs(left);
            bead[now] = bead[left] + bead[right];
            return ret;
        }
        else {
            ret = dfs(right);
            bead[now] = bead[left] + bead[right];
            return ret;
        }
    }
}

int main() {
    int N; cin >> N;
    for(int i = 1; i <= N; i++) {
        int U, V; cin >> U >> V;
        if(U == -1) U = 0;
        if(V == -1) V = 0;
        tree[i] = make_pair(U, V);
    }
    int K; cin >> K;
    for(int i = 0; i < K - 1; i++) {
        dfs(1);
    }
    cout << dfs(1);
}
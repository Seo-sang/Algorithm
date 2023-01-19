#include <bits/stdc++.h>
#define P pair<int,int>

using namespace std;

const int MN = 200001;
P tree[MN];


int main() {
    int N; cin >> N;
    long long K;
    for(int i = 1; i <= N; i++) {
        cin >> tree[i].first >> tree[i].second;
    }
    cin >> K;
    int now = 1;
    while(true) {
        int left= tree[now].first;
        int right = tree[now].second;

        if(left == -1 && right == -1) break;
        else if(left == -1) now = right;
        else if(right == -1) now = left;
        else if(K % 2) {
            now = left;
            K = K / 2 + 1;
        }
        else {
            now = right;
            K /= 2;
        } 
    }
    cout << now;
}
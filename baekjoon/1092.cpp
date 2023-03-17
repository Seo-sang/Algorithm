#include <bits/stdc++.h>
#define P pair<int,int>
using namespace std;

const int MN = 51;
vector<int> limit;
vector<int> box;

int main() {
    int N, M; cin >> N;
    int a;
    for(int i = 0; i < N; i++) {
        cin >> a;
        limit.push_back(a);
    }

    cin >> M;
    for(int i = 0; i < M; i++) {
        int a; cin >> a;
        box.push_back(a);
    }

    sort(limit.begin(), limit.end(), greater<int>());
    sort(box.begin(), box.end());

    int mnum = 0;
    int sum = 0;
    for(int i = 0; i < N - 1; i++) {
        auto it1 = upper_bound(box.begin(), box.end(), limit[i]);
        auto it2 = upper_bound(box.begin(), box.end(), limit[i + 1]);
        mnum = max(mnum, it1 - it2);
        sum += (it1 - it2);
    }


}
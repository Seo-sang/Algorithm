#include <bits/stdc++.h>

using ll = long long;
using namespace std;

const int MN = 100001;
ll arr[MN];

ll divNconq(int start, int end) {
    int mid = (start + end) / 2;
}


int main() {
    int N;
    while(true) {
        cin >> N;
        memset(arr, 0, sizeof(arr));
        if(!N) break;
        for(int i = 0; i < N; i++)
            cin >> arr[i];

        cout << divNconq(0, N - 1);
    }
}
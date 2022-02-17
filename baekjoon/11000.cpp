#include <bits/stdc++.h>

using namespace std;
const int MN = 200001;
pair<int,int> arr[MN];
vector<int> end;
int main() {
    int N; cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> arr[i].first >> arr[i].second;

    sort(arr + 1, arr + N + 1);
    int ans = 0;
    for(int i = 1; i <= N; i++) {
        auto it = lower_bound();
    }
}
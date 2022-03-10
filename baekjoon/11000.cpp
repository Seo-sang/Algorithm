#include <bits/stdc++.h>

using namespace std;
const int MN = 200001;
pair<int,int> arr[MN];
multiset<int> fin;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    for(int i = 0; i < N; i++)
        cin >> arr[i].first >> arr[i].second;

    sort(arr, arr + N);
    for(int i = 0; i < N; i++) {
        if(fin.empty()) fin.insert(arr[i].second);
        else {
            if(*fin.begin() <= arr[i].first) fin.erase(fin.begin());
            fin.insert(arr[i].second);
        }
    }

    cout << fin.size();
}
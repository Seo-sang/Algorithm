#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int,int>> arr;

bool cmp(pair<int,int> a, pair<int,int> b) {
    if(a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

int main() {
    int N; cin >> N;
    int a, b; 
    for(int i = 0; i < N; i++) {
        cin >> a >> b;
        arr.push_back({a, b});
    }

    sort(arr.begin(), arr.end(), cmp);

    for(int i = 0; i < N; i++)
        cout << arr[i].first << ' ' <<arr[i].second << '\n';
}
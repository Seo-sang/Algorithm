#include <bits/stdc++.h>

using namespace std;

map<int, string> title;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M; cin >> N >> M;
    string str;
    int limit;
    vector<int> arr;

    for(int i = 0; i < N; i++) {
        cin >> str >> limit;
        arr.push_back(limit);
        if(title.find(limit) == title.end())
            title[limit] = str;
    }
    while(M--) {
        int input; cin >> input;
        auto it = lower_bound(arr.begin(), arr.end(), input);
        cout << title[*it] << '\n';
    }
}
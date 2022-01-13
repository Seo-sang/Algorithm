#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

set<string> s;
vector<string> ans;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M; cin >> N >> M;
    for(int i = 0; i < N; i++) {
        string str; cin >> str;
        s.insert(str);
    }

    for(int i = 0; i < M; i++) {
        string str; cin >> str;
        if(s.find(str) != s.end())
            ans.push_back(str);
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for(string str : ans)
        cout << str << '\n';
}
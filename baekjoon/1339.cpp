#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>
#include <vector>

using namespace std;
const int MN = 11;
map<char,int> m;
vector<pair<char, int>> alpha;

bool cmp(pair<char, int> a, pair<char,int> b) {
    return a.second > b.second;
}

int main() {
    int N; cin >> N;
    string s;
    for(int i = 0; i < N; i++) {
        cin >> s;
        int l = s.size() - 1;
        for(int j = 0; j < s.size(); j++) {
            m[s[j]] += pow(10, l - j);
        }
    }
    for(auto it = m.begin(); it != m.end(); it++)
        alpha.push_back({it->first, it->second});
    sort(alpha.begin(), alpha.end(), cmp);
    int ans = 0;
    int num = 9;

    for(pair<char,int> e : alpha) {
        ans += (num * e.second);
        num--;
    }

    cout << ans;
}
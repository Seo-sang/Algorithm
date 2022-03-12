#include <bits/stdc++.h>

using namespace std;
vector<char> ans;
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, K; cin >> N >> K;
    string number; cin >> number;
    ans.push_back(number[0]);
    int i;
    for(i = 1; i < number.size() && K; i++) {
        while(K && !ans.empty() && ans.back() < number[i]) {
            ans.pop_back();
            K--;
        }
        ans.push_back(number[i]);
    }
    for(; i < number.size(); i++)
        ans.push_back(number[i]);

    while(K--)
        ans.pop_back();

    for(char c : ans)
        cout << c;
}
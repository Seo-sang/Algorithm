#include <bits/stdc++.h>

using namespace std;
const int MN = 7500001;

bool s[MN];
vector<int> ans;
int main() {
    int K; cin >> K;
    s[1] = true;
    for(int i = 2; i * i <= MN; i++) {
        if(s[i])
            continue;
        for(int j = i * i; j <= MN; j += i)
            s[j]= true;
    }
    for(int i = 2; i <= MN; i++)
        if(!s[i])
            ans.push_back(i);
            
    cout << ans[K - 1] << '\n';
}
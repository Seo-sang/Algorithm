#include <bits/stdc++.h>

using namespace std;

int main() {
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    int ans = 0;
    if(str1.size() >= str2.size()) {
        int idx = 0;
        while(idx <= str1.size()) {
            int pos = str1.find(str2, idx);
            if(pos != string::npos) {
                idx = pos + str2.size();
                ans++;
            }
            else {
                break;
            }
        }
    }
    cout << ans;
}
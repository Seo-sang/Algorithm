#include <iostream>

using namespace std;

const int MN = 4001;
int arr[MN][MN];

int main() {
    string s1, s2; cin >> s1 >> s2;

    s1 = ' ' + s1;
    s2 = ' ' + s2;
    int ans = 0;
    for(int i = 1; i < s1.size(); i++) {
        for(int j = 1; j < s2.size(); j++) {
            if(s1[i] == s2[j]) 
                arr[i][j] = arr[i-1][j-1] + 1;
            ans = max(ans, arr[i][j]);
        }
    }

    cout << ans;
}
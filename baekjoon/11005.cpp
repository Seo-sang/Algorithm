#include <bits/stdc++.h>

using namespace std;

char c[37] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 
                'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L',
                'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

int main() {
    int N, B; cin >> N >> B;
    string ans = "";
    while(N > 0) {
        ans += c[N % B];
        N /= B;
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
}
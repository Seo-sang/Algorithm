#include <iostream>
#include <map>

using namespace std;
map<string, int> m;

int main() {
    int N; cin >> N;
    string ans;
    int mnum = 0;
    while(N--) {
        string s; cin >> s;
        m[s]++;
        if(m[s] > mnum) {
            mnum = m[s];
            ans = s;
        }
        else if(m[s] == mnum) {
            ans = min(ans, s);
        }
    }
    cout << ans;
}
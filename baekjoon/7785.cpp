#include <iostream>
#include <set>

using namespace std;

set<string> s;

int main() {
    ios::sync_with_stdio(false);  cin.tie(NULL);
    int N; cin >> N;
    while(N--) {
        string who, did; cin >> who >> did;
        if(did == "enter") s.insert(who);
        else s.erase(who);
    }

    for(auto it = s.rbegin(); it != s.rend(); it++)
        cout << *it << '\n';
}
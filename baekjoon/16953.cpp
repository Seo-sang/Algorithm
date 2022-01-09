#include <iostream>
#include <queue>

using namespace std;

const int MN = 1e9;

int main() {
    long long A, B; cin >> A >> B;
    queue<pair<long long,int>> q;
    q.push({A, 1});
    if(A == B) {
        cout << 1;
        return 0;
    }
    while(!q.empty()) {
        pair<long long,int> now = q.front(); q.pop();
        long long nxt;
        nxt = now.first * 2;
        if(nxt == B) {
            cout << now.second + 1;
            return 0;
        }
        if(nxt < B && nxt >= 1) {
            q.push({nxt, now.second + 1});
        }
        
        nxt = now.first * 10 + 1;
        if(nxt == B) {
            cout << now.second + 1;
            return 0;
        }
        if(nxt < B && nxt >= 1) {
            q.push({nxt, now.second + 1});
        }
    }
    cout << -1;
}
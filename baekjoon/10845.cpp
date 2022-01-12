#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    queue<int> q;
    while(N--) {
        string s; cin >> s;
        if(s == "push") {
            int n; cin >> n;
            q.push(n);
        }
        else if(s == "pop") {
            if(q.empty())
                cout << "-1\n";
            else {
                cout << q.front() << '\n';
                q.pop();
            }
        }
        else if(s == "size") {
            cout << q.size() << '\n';
        }
        else if(s == "empty") {
            cout << q.empty() << '\n';
        }
        else if(s == "front") {
            if(q.empty())
                cout << "-1\n";
            else
                cout << q.front() << '\n';
        }
        else if(s == "back") {
            if(q.empty())
                cout << "-1\n";
            else
                cout << q.back() << '\n';
        }
    }
}
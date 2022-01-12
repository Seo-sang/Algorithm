#include <iostream>
#include <deque>

using namespace std;

int main() {
    int N, K; cin >> N >> K;
    deque<int> dq;

    for(int i = 1; i <= N; i++)
        dq.push_back(i);
    
    int idx = 0;
    cout << "<";
    while(!dq.empty()) {
        cout << dq[(idx + K - 1) % dq.size()];
        dq.erase(dq.begin() + ( idx + K - 1) % dq.size());
        idx = (idx + K - 1) % (dq.size() + 1);
        if(!dq.empty())
            cout << ", ";
    }
    cout << ">";
}
#include <iostream>
#include <deque>

using namespace std;
deque<int> dq;
int main() {
    int N; cin >> N;
    for(int i = 1; i <= N; i++)
        dq.push_back(i);
    while(dq.size() != 1) {
        cout << dq.front() << ' ';
        dq.pop_front();
        dq.push_back(dq.front());
        dq.pop_front();
    }
    cout << dq.front();
}
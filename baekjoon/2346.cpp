#include <bits/stdc++.h>

#define pii pair<int,int>

using namespace std;

deque<pii> arr;

int main() {
    int N; cin >> N;

    for(int i = 0; i < N; i++) {
        int a; cin >> a;
        arr.push_back(pair<int,int>(i, a));
    }
    while(true) {
        cout << arr.front().first + 1 << ' ';
        int cnt = arr.front().second;
        if(arr.size() == 1) break;
        arr.pop_front();
        if(cnt > 0) cnt--;
        while(cnt) {
            if(cnt > 0) {
                arr.push_back(arr.front());
                arr.pop_front();
            }
            else {
                arr.push_front(arr.back());
                arr.pop_back();
            }
            cnt > 0 ? cnt-- : cnt++;
        }
    }
}
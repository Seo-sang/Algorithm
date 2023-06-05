#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    list<int> arr;
    for(int i = 1; i <= N; i++) {
        int a; cin >> a;
        auto it = arr.end();
        while(a--) it--;
        arr.insert(it, i);
    }

    for(int e : arr) cout << e << ' ';
}
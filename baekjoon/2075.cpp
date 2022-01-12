#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

const int MN = 1501;

set<int> arr;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            int a; cin >> a;
            if(arr.size() < N)
                arr.insert(a);
            else {
                if(*(arr.begin()) < a) {
                    arr.erase(*(arr.begin()));
                    arr.insert(a);
                }
            }
        }
    }
    cout << *(arr.begin());
    
}
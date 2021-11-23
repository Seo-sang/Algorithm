#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MN = 100001;

vector<int> arr;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    for(int i = 0; i < N; i++) {
        int a; cin >> a;
        arr.push_back(a);
    }
        

    sort(arr.begin(), arr.end());

    int M; cin >> M;
    for(int i = 0; i < M; i++) {
        int p; cin >> p;
        int l = 0, r = N-1;
        int mid;
        while(l <= r) {
            mid = (l + r) / 2;
            if(arr[mid] == p) break;
            else if(arr[mid] < p) l = mid + 1;
            else r = mid - 1;
        }
        if(arr[mid] == p) cout << "1\n";
        else cout << "0\n";
    }
}
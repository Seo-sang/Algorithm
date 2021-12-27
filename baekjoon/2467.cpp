#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

vector<int> arr;

int main() {
    int N; cin >> N;
    int first, second;
    for(int i = 0; i < N; i++) {
        int a; cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());
    int mnum = 2e9 + 1;
    int l = 0, r = N-1;
    while(l < r) {
        if(abs(arr[r] + arr[l]) < mnum) {
            mnum = abs(arr[r] + arr[l]);
            first = arr[l];
            second = arr[r];
        }
        if(abs(arr[l] + arr[r-1]) < abs(arr[l+1] + arr[r])) r--;
        else l++;
    }

    cout << first << ' ' << second;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    string s; cin >> s;
    vector<int> arr;
    int sum = 0;
    for(char c : s) {
        arr.push_back(c - '0');
        sum += arr.back();
    }
    sort(arr.begin(), arr.end(), greater<int>());
    if(arr.back() != 0 || sum % 3 != 0) {
        cout << -1;
        return 0;
    }
    else {
        for(int e : arr)
            cout << e;
    }
}
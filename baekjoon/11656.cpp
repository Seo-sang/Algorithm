#include <bits/stdc++.h>

using namespace std;

int main() {
    string str; cin >> str;
    vector<string> arr;
    arr.push_back(str);
    for(int i = 1; i < str.size(); i++) {
        arr.push_back(str.substr(i));
    }
    sort(arr.begin(), arr.end());
    for(string s : arr)
        cout << s << '\n';
}
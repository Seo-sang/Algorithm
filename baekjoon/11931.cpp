#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;

int main() {
    int N; cin >> N;
    int a;
    for(int i = 0; i < N; i++) {
        cin >> a;
        arr.push_back(a);
    }

    sort(arr.begin(), arr.end(), greater<int>());

    for(int i = 0; i < N; i++)
        cout << arr[i] << '\n';
}
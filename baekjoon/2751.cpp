#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[1000001];

int main() {
    int N; cin >> N;
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr, arr+N);

    for(int i = 0; i < N; i++)
        cout << arr[i] << '\n';
}
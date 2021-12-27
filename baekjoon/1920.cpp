#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MN = 101010;

int arr[MN];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N, M; cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    cin >> M;
    for(int i = 0; i < M; i++) {
        int a; cin >> a;
        cout << binary_search(arr, arr+ N, a) << '\n';
    }
}
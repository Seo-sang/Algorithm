#include <iostream>
#include <algorithm>

using namespace std;

const int MN = 1001;
int arr[MN];

int main() {
    int N; cin >> N;

    for(int i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr, arr + N);

    int num = 1;
    for(int i = 0; i < N; i++) {
        if(num < arr[i]) break;
        num += arr[i];
    }

    cout << num;
}
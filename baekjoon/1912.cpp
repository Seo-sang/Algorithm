#include <iostream>

using namespace std;

int arr[100001];

int main() {
    int N; cin >> N;
    int idx = 1;
    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
        if(arr[i] > arr[idx]) idx = i;
    }
    if(arr[idx] <= 0) cout << arr[idx];
    else {
        int rst = -1e9;
        int sum = 0;
        for(int i = 1; i <= N; i++) {
            sum += arr[i];
            if(sum > rst) rst = sum;
            if(sum < 0) sum = 0;
        }

        cout << rst;
    }
}
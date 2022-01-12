#include <iostream>

using namespace std;

const int MN = 500001;
int arr[MN];

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main() {
    int N; cin >> N;
    for(int i = 0; i < N; i++) 
        cin >> arr[i];
    int ans = 0;
    for(int i = 0; i < N - 1; i++) {
        for(int j = 0; j < N - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                //cout << arr[j] << ' ' << arr[j+1];
                swap(arr[j], arr[j + 1]);
                ans++;
            }
        }
    }
    cout << ans;
}
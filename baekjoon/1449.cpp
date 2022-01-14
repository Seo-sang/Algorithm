#include <iostream>
#include <algorithm>

using namespace std;
const int MN = 1001;
int arr[MN];

int main() {
    int N, L; cin >> N >> L;
    int ans = 1;
    int tape = 1;
    for(int i = 1;  i <= N; i++)
        cin >> arr[i];

    sort(arr, arr + N + 1);
    
    for(int i = 2; i <= N; i++) {
        if(arr[i] - arr[i-1] + tape > L) {
            ans++;
            tape = 1;
        }
        else {
            tape += (arr[i] - arr[i-1]);
        }
    }
    cout << ans;
}
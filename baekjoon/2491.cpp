#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MN = 100001;

int arr[MN];
int increase[MN];
int decrease[MN];

int main() {
    int N; cin >> N;
    int ans = 1;
    cin >> arr[0];
    increase[0] = 1;
    decrease[0] = 1;
    for(int i = 1; i < N; i++) {
        cin >> arr[i];
        if(arr[i-1] <= arr[i])
            increase[i] = increase[i-1] + 1;
        else
            increase[i] = 1;
        if(arr[i-1] >= arr[i])
            decrease[i] = decrease[i-1] + 1;
        else
            decrease[i] = 1;

        ans = max(max(decrease[i], increase[i]), ans);
    }
    cout << ans;
}
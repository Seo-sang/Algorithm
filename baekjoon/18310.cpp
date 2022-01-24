#include <bits/stdc++.h>

using namespace std;
const int MN = 200001;
int arr[MN];
int front[MN];
int back[MN];

int main() {
    int N; cin >> N;
    for(int i = 1; i <= N; i++)
        cin >> arr[i];

    sort(arr + 1, arr + N + 1);
    
    cout << arr[(N + 1) / 2] << '\n';

}
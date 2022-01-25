#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MN = 1001;
int A[MN];
int B[MN];
vector<int> arr1;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T; cin >> T;
    int N; cin >> N;

    int sum = 0;
    ll ans = 0;
    int a;
    for(int i = 1; i <= N; i++) {
        cin >> a;
        sum += a;
        A[i] = sum;
        for(int j = 0; j < i; j++) {
            arr1.push_back(A[i] - A[j]);
        }
    }
    sort(arr1.begin(), arr1.end());
    sum = 0;
    int M; cin >> M;
    for(int i = 1; i <= M; i++) {
        cin >> a;
        sum += a;
        B[i] = sum;

        for(int j = 0; j < i; j++) {
            int num = B[i] - B[j];
            num = T - num;
            auto it1 = upper_bound(arr1.begin(), arr1.end(), num);
            auto it2 = lower_bound(arr1.begin(), arr1.end(), num);
            ans += (it1 - it2);
        }
    }
    
    cout << ans;

    
}
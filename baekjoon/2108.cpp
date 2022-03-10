#include <bits/stdc++.h>

using namespace std;
const int MN = 500001;
int arr[MN];
int cnt[8001];
int main() {
    double sum = 0;
    int N; cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
        sum += arr[i];
        cnt[arr[i] + 4000]++;
    }
    sort(arr, arr + N);
    int mcnt = 0;
    for(int i = 0; i < 8001; i++)
        if(mcnt < cnt[i]) mcnt = cnt[i];
    bool flag = false;
    int mnum;
    for(int i = 0; i < 8001; i++) {
        if(mcnt == cnt[i]) {
            if(flag) {
                mnum = i;
                break;
            }
            flag = true;
            mnum = i;
        }
    }
    int rnd = round(sum / N);
    cout << rnd << '\n' << arr[N / 2] << '\n' << mnum - 4000 << '\n' << arr[N-1] - arr[0];
}
#include <bits/stdc++.h>

using namespace std;
const int MN = 4000001;
bool s[MN];
vector<int> arr;

int main() {
    int N; cin >> N;
    //에라토스테네스 체 소수 구하기
    for(int i = 2; i * i <= N; i++) {
        if(s[i]) continue;
        for(int j = i * 2; j <= N; j += i)
            s[j] = true;
    }

    //소수 배열 만들기
    for(int i = 2; i <= N; i++)
        if(!s[i]) arr.push_back(i);
        

    //투포인터로 경우의 수 구하기
    int left = 0, right = 0, sum = 0, ans = 0;
    while(true) {
        //cout << sum << ' ' << left << ' ' << right << endl;
        if(sum >= N) sum -= arr[left++];
        else if(right == arr.size()) break;
        else sum += arr[right++];
        if(sum == N) ans++;
    }
    cout << ans;
}
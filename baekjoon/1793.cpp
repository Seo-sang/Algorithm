#include <bits/stdc++.h>
using namespace std;

const int MN = 250;
string arr[MN];

int main() {
    int N;
    arr[0] = "1", arr[1] = "1", arr[2] = "3";

    for(int i = 3; i <= MN; i++) {
        arr[i] = string(500, '0');
        for(int j = 0; j < max(arr[i-2].size(), arr[i-1].size()); j++) {
            int tmp = arr[i][j] - '0';
            if(j < arr[i-2].size())
                tmp += (arr[i-2][j] - '0') * 2;
            if(j < arr[i-1].size())
                tmp += arr[i-1][j] - '0';
            arr[i][j] = (tmp % 10) + '0';
            arr[i][j+1] = (tmp / 10) + '0';
        }
    }

    for(int i = 1; i <= MN; i++)
        reverse(arr[i].begin(), arr[i].end());

    while(cin >> N) {
        bool chk = false;
        for(int i = 0; i < arr[N].size(); i++) {
            if(arr[N][i] == '0' && !chk) continue;
            chk = true;
            cout << arr[N][i];
        }
        cout << '\n';
    }
}
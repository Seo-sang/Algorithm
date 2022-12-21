#include <bits/stdc++.h>

using namespace std;

void divNconq(int start, int end, int k, int pos) {
    int len = (end - start + 1 - (k + 3)) / 2;
    if(pos <= start + len - 1)
        divNconq(start, start + len - 1, k - 1, pos);
    else if(end - len + 1 <= pos)
        divNconq(end - len + 1, end, k - 1, pos);
    else {
        if(start + len == pos) cout << "m";
        else cout << "o";
    }
}

int main() {
    int N; cin >> N;
    int k = 0, len = 3;
    while(len < N) {
        k++;
        len = len * 2 + (k + 3);
    }
    divNconq(0, len - 1, k, N - 1);
}
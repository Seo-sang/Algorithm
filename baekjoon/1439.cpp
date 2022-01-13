#include <iostream>

using namespace std;

int main() {
    string S; cin >> S;
    char now = S[0];
    int cnt = 1;
    for(int i = 1; i < S.size(); i++) {
        if(S[i] != now) {
            cnt++;
            now = S[i];
        }
    }
    if(cnt % 2) //홀수
        cout << cnt / 2;
    else //짝수
        cout << (cnt - 1) / 2 + 1;
}
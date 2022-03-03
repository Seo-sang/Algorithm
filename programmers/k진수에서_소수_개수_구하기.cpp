#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MN = 1e6 + 1;
bool isSieve(ll n) {
    if(n == 0 || n == 1) return true;
    for(ll i = 2; i * i <= n; i++) {
        if(n % i == 0) return true;
    }
    return false;
}

int solution(int n, int k) {
    int answer = 0;
    
    int idx = 0;
    while(n > (int)pow(k, idx)) {
        idx++;
    }
    idx--;
    ll now = 0;
    while(idx >= 0) {
        ll q = (int)pow(k, idx);
        ll v = n / q;
        if(v == 0) {
            if(!isSieve(now))
                answer++;
            now = 0;
        }
        else
            now = now * 10 + v;
        n %= q;
        idx--;
    }
    if(!isSieve(now))
        answer++;
    return answer;
}
#include <iostream>

using namespace std;

const long long MN = 1e7;

bool s[MN + 1];

int main() {
    long long A, B; cin >> A >> B;
    s[1] = 1;
    int cnt = 0;
    for(long long i = 2; i * i <= B; i++) {
        if(s[i]) continue;
        for(long long j = i * 2; j <= MN; j += i) {
            s[j] = 1;
        }
        for(long long j = i * i; j <= B && !(j % i); j *= i) { //오버플로우 방지
            if(j >= A) cnt++;
        }
    }

    cout << cnt;
}
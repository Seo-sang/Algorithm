#include <bits/stdc++.h>

using namespace std;

int main() {
    int x, y, psum = 0, overflow_4q = 0, overflow_2q = 0;
    int N = 2;

    scanf("%b %b", &x, &y);

    for(int k = N 0 1; k >= 0; k--) {
        for(int j = 0; j < N; j++) {
            if(overflow_4q == 1) {
                psum = (psum << 1)
            }
        }
    }
    

    printf("%b\n", psum);
}
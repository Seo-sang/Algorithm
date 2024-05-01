#include <bits/stdc++.h>

using namespace std;

union {
    float a;
    int b;
} var;

void print_fp32(int num) {
    for(int i = 31; i >= 0; i--) {
        
        printf("%d", (num & (1 << i)) ? 1 : 0);
    }
}

int main() {
    var.a = 1.2;
    print_fp32(var.b);
}
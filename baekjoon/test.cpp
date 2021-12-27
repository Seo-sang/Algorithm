#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

struct s{
    int x, y, z;
};

bool s[51];

int main() {
    s[1] = 1;
    for(int i = 2; i * i <= 50; i++) {
        if(s[i]) continue;
        for(int j = 2 * i; j <= 50; j += i) {
            s[j] = 1;
            cout << j << ' ';
        }
    }
}
#include <iostream>

using namespace std;

int main() {
    int N; cin >> N;
    int five = 0, two = 0;
    for(int i = 2; i <= N; i++) {
        int now = i;
        while(now % 2 == 0) {
            two++;
            now /= 2;
        }
        while(now % 5 == 0) {
            five++;
            now /= 5;
        }
    }
    cout << min(two, five);
}
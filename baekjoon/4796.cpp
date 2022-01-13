#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int L, P, V;
    int cs = 1;
    while(true) {
        cin >> L >> P >> V;
        if((L || P || V) == 0) break;
        int days = V / P;
        int N = L * days;
        N += min(L, V - days * P);
        cout << "Case " << cs++ <<": " << N << '\n';
    }
}
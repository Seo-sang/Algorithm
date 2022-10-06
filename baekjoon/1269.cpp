#include <bits/stdc++.h>

using namespace std;
set<int> A, B;

int main() {
    int Asize, Bsize; cin >> Asize >> Bsize;
    int a, cnt = 0;
    while(Asize--) {
        cin >> a;
        A.insert(a);
    }
    while(Bsize--) {
        cin >> a;
        B.insert(a);
        if(A.find(a) != A.end()) cnt++;
    }
    cout << A.size() + B.size() - 2 * cnt;

}
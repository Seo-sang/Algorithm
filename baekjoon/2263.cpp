#include <iostream>
#include <vector>

using namespace std;
const int MN = 100001;
int in[MN];
int post[MN];
int pos[MN];

void divNconq(int instart, int inend, int poststart, int postend) {
    if(instart > inend || poststart > postend) return;

    int rootidx = pos[post[postend]];
    int lsize = rootidx - instart;
    int rsize = inend - rootidx - 1;
    cout << post[postend] << ' ';

    divNconq(instart, rootidx - 1, poststart, poststart + lsize - 1);
    divNconq(rootidx + 1, inend, poststart + lsize, postend - 1);
}

int main() {
    ios::sync_with_stdio(false);
    int N; cin >> N;

    for(int i = 1; i <= N; i++) {
        cin >> in[i];
        pos[in[i]] = i;
    }

    for(int i = 1; i <= N; i++)
        cin >> post[i];
        
    divNconq(1, N, 1, N);
}
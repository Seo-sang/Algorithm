#include <bits/stdc++.h>
#define ll long long

using namespace std;

const int MN = 500001;
int A[MN];
int B[MN];
int tmp[MN];
int pos[MN * 2];
ll seg[MN * 3];
int N;

void update(int node, int s1, int e1, int s2, int e2) {
    seg[node] = seg[node * 2] + seg[node * 2 + 1];
    int idx1 = s1, idx2 = s2;
    int idx = s1;
    while(idx1 <= e1 && idx2 <= e2) {
        if(pos[B[idx1]] < pos[B[idx2]]) {
            tmp[idx++] = B[idx1];
            idx1++;
            seg[node] += (idx2 - s2);
        }
        else {
            tmp[idx++] = B[idx2];
            idx2++;
        }
    }
    while(idx1 <= e1) {
        tmp[idx++] = B[idx1++];
        seg[node] += (idx2 - s2);
    }
    while(idx2 <= e2) {
        tmp[idx++] = B[idx2++];
    }

    memcpy(B + s1, tmp + s1, sizeof(int) * (e2 - s1 + 1));
}

void divNconq(int node, int start, int end) {
    if(start == end) {
        seg[node] = 0;
        return;
    }
    int mid = (start + end) / 2;
    divNconq(node * 2, start, mid);
    divNconq(node * 2 + 1, mid + 1, end);

    update(node, start, mid, mid + 1, end);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        pos[A[i]] = i;
    }    
    for(int i = 0; i < N; i++)
        cin >> B[i];

    divNconq(1, 0, N-1);

    cout << seg[1];
}
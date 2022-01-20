#include <bits/stdc++.h>

using namespace std;
const int MN = 500001;
int A[MN];
int B[MN];
int pos[MN * 2];
int seg[MN * 3];
int N;

void update(int node, int s1, int e1, int s2, int e2) {
    seg[node] = seg[node * 2] + seg[node * 2 + 1];

    for(int i = s2; i <= e2; i++)
        for(int j = s1; j <= e1; j++)
            if(pos[B[i]] < pos[B[j]])
                seg[node]++;
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
#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct node {
    int a, b, c;
    node(int a, int b, int c) : a(a), b(b), c(c) {}
};

vector<node> arr;

ll f(int mid) {
    ll ret = 0;
    for(node e : arr) {
        if(mid < e.a) continue;
        ret += ((min(mid, e.b) - e.a) / e.c + 1);
    }

    return ret;
}

int main() {
    int N, K, D; cin >> N >> K >> D;
    while(K--) {
        int A, B, C; cin >> A >> B >> C;
        arr.push_back(node(A, B, C));
    }
    int left = 0, right = N + 1;
    while(left + 1 < right) {
        int mid = (left + right) / 2;
        ll ret = f(mid);

        if(ret >= D) right = mid;
        else left = mid;
    }

    cout << right;
}
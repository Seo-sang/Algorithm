#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MN = 20;
const ll INF = 1e15;
int N;
ll seg[MN * 3];
vector<int> num;
vector<char> op;

ll cal(ll a, ll b, char c) {
    switch (c) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
    }
}

ll init(int node, int left, int right, int start, int end) {
    if(end < left || right < start) return seg[node];
    
    if(left == right) return seg[node] = num[left];
    int mid = (left, right) / 2;
    ll ret = cal(init(node * 2, left, mid, start, end), init(node * 2 + 1, mid + 1, right, start, end), op[mid]);
    for(int s = left; s <= mid; s++) {
        for(int e = mid + 1; e <= right; e++) {

        }
    }
}


int main() {
    cin >> N;
    string exp; cin >> exp;
    for(int i = 0; i < N; i++) {
        if(i % 2 == 0) num.push_back(exp[i] - '0');
        else num.push_back(exp[i]);
    }

}
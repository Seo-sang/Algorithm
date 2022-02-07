#include <bits/stdc++.h>

using namespace std;
const int MN = 27;
pair<char, char> g[MN];

void preorder(char n) {
    cout << n;
    if(g[n - 'A'].first != '.')
        preorder(g[n - 'A'].first);
    if(g[n - 'A'].second != '.')
        preorder(g[n - 'A'].second);
}

void inorder(char n) {
    if(g[n - 'A'].first != '.')
        inorder(g[n - 'A'].first);
    cout << n;
    if(g[n - 'A'].second != '.')
        inorder(g[n - 'A'].second);
}

void postorder(char n) {
    if(g[n - 'A'].first != '.')
        postorder(g[n - 'A'].first);
    if(g[n - 'A'].second != '.')
        postorder(g[n - 'A'].second);
    cout << n;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;

    for(int i = 0; i < N; i++) {
        char a, b, c; cin >> a >> b >> c;
        g[a - 'A'].first = b;
        g[a - 'A'].second = c;
    }
    preorder('A');
    cout << '\n';
    inorder('A');
    cout << '\n';
    postorder('A');

}
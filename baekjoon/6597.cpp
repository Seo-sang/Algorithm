#include <bits/stdc++.h>
#define P pair<char,char>

using namespace std;

map<char, P> tree;

void make_tree(string preorder, string inorder) {
    char root = preorder[0];
    int pos = inorder.find(root);
    tree[root] = make_pair(-1, -1);
    if(pos != 0) {
        string leftpreorder = preorder.substr(1, pos);
        string leftinorder = inorder.substr(0, pos);
        make_tree(leftpreorder, leftinorder);
        tree[root].first = leftpreorder[0];
    }
    if(pos != inorder.size() - 1) {
        string rightpreorder = preorder.substr(pos + 1);
        string rightinorder = inorder.substr(pos + 1);
        make_tree(rightpreorder, rightinorder);
        tree[root].second = rightpreorder[0];
    }
}

void print(char now) {
    if(tree[now].first != -1) 
        print(tree[now].first);
    if(tree[now].second != -1)
        print(tree[now].second);

    cout << now;
}

int main() {
    string preorder, inorder;
    while(cin >> preorder >> inorder) {
        tree.clear();
        make_tree(preorder, inorder);
        print(preorder[0]);
        cout << '\n';
    }
}
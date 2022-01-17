#include <iostream>
#include <vector>

using namespace std;
const int MN = 10001;
pair<int,int> tree[MN];
vector<int> pos[MN];
bool isroot[MN];
int column = 1;

void inorder(int n, int level) {
    if(tree[n].first != -1)
        inorder(tree[n].first, level + 1);

    pos[level].push_back(column);
    column++;

    if(tree[n].second != -1)
        inorder(tree[n].second, level + 1);
}

int main() {
    int N; cin >> N;
    for(int i = 0; i < N; i++) {
        int node, left, right; cin >> node >> left >> right;
        tree[node].first = left;
        tree[node].second = right;
        isroot[left] = true;
        isroot[right] = true;
    }
    int root;
    for(int i = 1; i <= N; i++) {
        if(!isroot[i]) {
            root = i;
            break;
        }
    }

    inorder(root, 1);

    int node = 1;
    for(int i = 2; i <= N; i++) {
        if(pos[i].empty()) continue;
        int a = pos[node].back() - pos[node].front();
        int b = pos[i].back() - pos[i].front();
        if(a < b)
            node = i;
    }
    
    cout << node << ' ' << pos[node].back() - pos[node].front() + 1;
}
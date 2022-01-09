#include <iostream>
#include <vector>

using namespace std;

const int MN = 10001;
int arr[MN];
pair<int,int> child[MN];
int N = 1;

void dfs(int now, int num) {
    //왼쪽 자식
    if(arr[num] < arr[now]) {
        if(child[now].first == 0)
            child[now].first = num;
        else
            dfs(child[now].first, num);
    }
    else {
        if(child[now].second == 0)
            child[now].second = num;
        else
            dfs(child[now].second, num);
    }
}

void postfix(int n) {
    if(child[n].first != 0)
        postfix(child[n].first);
    if(child[n].second != 0)
        postfix(child[n].second);
    if(arr[n] != 0)
        cout << arr[n] << '\n';
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int a;
    cin >> arr[N++];
    while(cin >> arr[N++]) {
        dfs(1, N-1);
    }
    postfix(1);
}
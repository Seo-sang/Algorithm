#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

const int MN = 500001;

stack<int> st;
int arr[MN];
int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    for(int i = 1; i  <= N; i++) {
        cin >> arr[i];
        while(!st.empty()) {
            if(arr[st.top()] > arr[i])
                break;
            st.pop();
        }
        if(st.empty())
            cout << "0 ";
        else
            cout << st.top() << ' ';
        st.push(i);
    }
}
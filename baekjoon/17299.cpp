#include <bits/stdc++.h>

using namespace std;
const int MN = 1000001;
int arr[MN + 1];
int NGF[MN + 1];
int F[MN + 1];

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int N; cin >> N;
    vector<int> st;
    memset(NGF, -1, sizeof(NGF));
    for(int i = 0; i < N; i++) {
        cin >> arr[i];
        F[arr[i]]++;
    }
    for(int i = 0; i < N; i++) {
        while(!st.empty() && F[arr[st.back()]] < F[arr[i]]) {
            NGF[st.back()] = arr[i];
            st.pop_back();
        }
        st.push_back(i);
    }
    for(int i = 0; i < N; i++) 
        cout << NGF[i] << ' ';
}
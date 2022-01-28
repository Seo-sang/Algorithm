#include <bits/stdc++.h>

using namespace std;
const int MN = 1001;
int A[MN];
int B[MN];

vector<int> Apizza;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int P; cin >> P;
    int M, N; cin >> M >> N;
    int sum = 0;
    long long ans = 0;
    for(int i = 0; i < M; i++) {
        cin >> A[i];
        sum += A[i];
    }
    if(sum == P) ans++;
    if(M != 1)
        Apizza.push_back(sum);
    
    for(int i = 0; i < M; i++) {
        sum = A[i];
        if(A[i] < P)
            Apizza.push_back(A[i]);
        if(A[i] == P) ans++;
        int j = (i + 1) % M;
        while(j != ((i - 1 + M) % M)) {
            sum += A[j];
            if(sum < P)
                Apizza.push_back(sum);
            if(sum == P) ans++;
            j = (j + 1) % M;
        }
    }
    sort(Apizza.begin(), Apizza.end());
    sum = 0;
    for(int i = 0; i < N; i++) {
        cin >> B[i];
        sum += B[i];
    }
    if(N != 1) {
    if(sum == P) ans++;
        auto it1 = lower_bound(Apizza.begin(), Apizza.end(), P - sum);
        auto it2 = upper_bound(Apizza.begin(), Apizza.end(), P - sum);
        ans += (it2 - it1);
    }

    for(int i = 0; i < N; i++) {
        sum = B[i];
        if(sum == P) ans++;
        if(P <= sum) continue;
        auto it1 = lower_bound(Apizza.begin(), Apizza.end(), P - sum);
        auto it2 = upper_bound(Apizza.begin(), Apizza.end(), P - sum);
        ans += (it2 - it1);
        int j = (i + 1) % N;

        while(j != (i - 1 + N) % N) {
            sum += B[j];
            if(sum == P) ans++;
            if(P <= sum) break;
            auto it1 = lower_bound(Apizza.begin(), Apizza.end(), P - sum);
            auto it2 = upper_bound(Apizza.begin(), Apizza.end(), P - sum);
            ans += (it2 - it1);
            j = (j + 1) % N;
        }
    }

    cout << ans;

}
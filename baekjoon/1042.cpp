#include <bits/stdc++.h>
#define P pair<int,int>

using namespace std;
const int MN = 2500;
const int MOD = 1e9 + 7;
P dp[MN];
string DNA;
map<string, string> convert;



int main() {
    cin >> DNA;
    int M; cin >> M;
    for(int i = 0; i < MN; i++)
        dp[i] = make_pair(-1, -1);

    while(M--) {
        string codon, am; cin >> codon >> am;
        convert[codon] = am;
    }
}
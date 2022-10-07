#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#define ll long long
using namespace std;

const int MN = 64;
bool vst[MN];
int L;

void dfs(int left, int right, ll e) {
    int mid = (left + right) / 2;
    if(e & (1LL << (L - mid))) {
        vst[mid] = true;
        //cout << mid << endl;
        if(left == right) return;
        dfs(left, mid - 1, e);
        dfs(mid + 1, right, e);
    }
}


vector<int> solution(vector<long long> numbers) {
    vector<int> answer;
    for(ll e : numbers) {
        int len;
        for(int i = 0; i < MN; i++) {
            if((1LL << i) & e) len = i + 1;
        }
        int i;
        for(i = 2; i - 1 < len; i *= 2);
        L = i - 1;
        memset(vst, 0, sizeof(vst));
        dfs(1, L, e);
        bool chk = true;
        for(int i = 0; i <= L; i++) {
            if((e & (1LL << (L - i))) && !vst[i]) {
                cout << i << endl;
                chk = false;
                break;
            }
        }
        if(chk) answer.push_back(1);
        else answer.push_back(0);

    }
    return answer;
}


int main() {
    vector<int> tmp = solution({1000000000000000});
    for(int e : tmp)
        cout << e << ' ';
}
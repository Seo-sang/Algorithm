#include <iostream>

using namespace std;

const int MN = 51;
string dept[MN];
string dest[MN];

int main() {
    int N, M; cin >> N >> M;

    for(int i = 0; i < N; i++)
        cin >> dept[i];

    bool chk = false;
    for(int i = 0; i < N; i++) {
        cin >> dest[i];
        for(int j = 0; j < M; j++) {
            if(dept[i][j] != dest[i][j])
                chk = true;
        }
    }

    int ans = 0;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if(dept[i][j] != dest[i][j]) {
                ans++;
                for(int r = 0; r < 3; r++) {
                    for(int c = 0; c < 3; c++) {
                        if((i + r) < N && (j + c) < M) {
                            dept[i + r][j + c] = ((dept[i + r][j + c] == '0') ? '1' : '0');
                        }
                        else {
                            cout << -1;
                            return 0;
                        }
                    }
                }
            }
        }
    }
    cout << ans;
}
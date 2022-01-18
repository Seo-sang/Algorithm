#include <iostream>
#include <algorithm>

using namespace std;
const int MN = 101;
const int INF = 1e9;

int floyd[MN][MN];

int main() {
    int N; cin >> N;
    fill(&floyd[0][0], &floyd[N][N+1], INF);
    /*
    for(int i = 1; i <= N; i++)
        floyd[i][i] = 0;
        */
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            int a; cin >> a;
            if(a != 0) floyd[i][j] = 1;
        }
    }

    for(int k = 1; k <= N; k++)
        for(int i = 1; i <= N; i++)
            for(int j = 1; j <= N; j++) 
                floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            (floyd[i][j] == INF) ? cout << "0 " : cout << "1 ";
        }
        cout << '\n';
    }
}
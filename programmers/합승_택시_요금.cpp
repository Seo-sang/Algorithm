#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;
int floyd[201][201];

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    fill(&floyd[0][0], &floyd[n][n+1], INF);
    
    for(int i =1; i <= n; i++)
        floyd[i][i] = 0;
    
    for(vector<int> v : fares) {
        floyd[v[0]][v[1]] = v[2];
        floyd[v[1]][v[0]] = v[2];
    }
    
    for(int k = 1;k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j]);
    
    answer = INF;
    
    for(int i = 1; i <= n; i++) {
        int tmp = floyd[s][i] + floyd[i][a] + floyd[i][b];
        if(tmp < 0) continue;
        answer = min(answer, tmp);
    }
    
    return answer;
}

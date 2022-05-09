#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>

#define P pair<int,int>

using namespace std;
const int MN = 151;
const int INF = 1e9;

//int dp[MN][MN];
vector<vector<int>> dp(MN, vector<int> (MN, INF));
int malp, mcop;

struct node {
    int alp, cop, cost;
};

int solution(int alp, int cop, vector<vector<int>> problems) {
    malp = 0, mcop = 0;
    for(vector<int>& v : problems) {
        malp = max(malp, v[0]);
        mcop = max(mcop, v[1]);
    }

    int answer = INF;
    queue<node> q; q.push({alp, cop, 0});
    while(!q.empty()) {
        node now = q.front(); q.pop();
        if(now.cost > dp[now.alp][now.cop]) continue;
        if(now.alp >= malp && now.cop >= mcop) answer = min(answer, now.cost);
        for(vector<int> &v : problems) {
            if(now.alp >= v[0] && now.cop >= v[1]) {
                int nalp = min(malp, now.alp + v[2]);
                int ncop = min(mcop, now.cop + v[3]);
                int ncost = now.cost + v[4];
                if(dp[nalp][ncop] > ncost) {
                    q.push({nalp, ncop, ncost});
                    dp[nalp][ncop] = ncost;
                }
                
            }
            else {
                int nalp = max(now.alp, v[0]);
                int ncop = max(now.cop, v[1]);
                int ncost = now.cost + max(0, v[0] - now.alp) + max(0, v[1] - now.cop);
                if(dp[nalp][ncop] > ncost) {
                    q.push({nalp, ncop, ncost});
                    dp[nalp][ncop] = ncost;
                }
            }
        }
    }
    return answer;
}
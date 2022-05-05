#include <string>
#include <vector>

using namespace std;

vector<int> answer;
int gap = 0;

void dfs(int now, int rest, int apeach, int ryan, vector<int>& info, vector<int> ans) {
    if(now == 11) {
        if(rest > 0) {
            for(int i = 0; i < info.size() && rest > 0; i++) {
                if(info[i] == 0) {
                    ans[i]++;
                    rest--;
                    ryan += (10 - i);
                }
            }
            if(rest > 0)
                ans[10] += rest;
        }
        if(gap <= ryan - apeach) {
            gap = ryan - apeach;
            answer = ans;
        }
        return;
    }
    if(info[now] == 0) {
        ans.push_back(0);
        dfs(now+1, rest, apeach, ryan, info, ans);
        ans.pop_back();
    }
    else {
        //라이언이 이기는 경우
        if(rest >= info[now] + 1) {
            ans.push_back(info[now] + 1);
            dfs(now+1, rest - ans.back(), apeach, ryan + 10 - now, info, ans);
            ans.pop_back();
        }
        //라이언이 지는 경우
        ans.push_back(0);
        dfs(now+1, rest, apeach + 10 - now, ryan, info, ans);
        ans.pop_back();
    }
}

vector<int> solution(int n, vector<int> info) {
    dfs(0, n, 0, 0, info, vector<int>());
    if(gap == 0) answer = vector<int>(1, -1);
    return answer;
}
#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>

using namespace std;

map<string, int> last;
set<int> q;

vector<int> solution(vector<string> gems) {
    vector<int> answer;
    answer.push_back(0);
    answer.push_back(1e6);
    int N = 0;
    int cnt = 0;
    for(int i = 0; i < gems.size(); i++) {
        string s = gems[i];
        if(last.find(s) == last.end())
            cnt++;
        else
            q.erase(last[s]);
        last[s] = i;
        q.insert(i);
        if(cnt > N) {
            answer[1] = i;
            answer[0] = *q.begin();
            N = cnt;
        }
        else {
            auto it = q.end();
            it--;
            if(*it - *q.begin() < answer[1] - answer[0])
                answer[0] = *q.begin(), answer[1] = *it;
        }
    }
    answer[0]++;
    answer[1]++;
    return answer;
}
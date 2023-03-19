#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    
    auto now = section.begin();
    while(now != section.end()) {
        auto it = upper_bound(now, section.end(), *now + m - 1);
        answer++;
        if(it == section.end()) break;
        now = it;
    }
    
    return answer;
}
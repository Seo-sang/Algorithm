#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>
#define P pair<int,int>

using namespace std;

const int MN = 100001;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    //가장 먼 곳부터 해결
    deque<P> delivery, pick;
    for(int i = n - 1; i >= 0; i--) {
        if(deliveries[i] > 0) delivery.push_back({i + 1, deliveries[i]});
        if(pickups[i] > 0) pick.push_back({i + 1, pickups[i]});
    }
    int now = 0;
    int dsum = 0, psum = 0;
    while(!delivery.empty() || !pick.empty()) {
        now += cap;
        int mnum = 0;
        if(!delivery.empty())
            mnum = max(mnum, delivery[0].first);
        if(!pick.empty())
            mnum = max(mnum, pick[0].first);
        answer += 2 * mnum;

        
        while(now > dsum && !delivery.empty()) {
            if(now >= dsum + delivery[0].second) {
                dsum += delivery[0].second;
                delivery.pop_front();
            }
            else break;
        }

        while(now > psum && !pick.empty()) {
            if(now >= psum + pick[0].second) {
                psum += pick[0].second;
                pick.pop_front();
            }
            else break;
        }

    }

    return answer;
}

#include <string>
#include <vector>
#include <iostream>
#include <queue>
#define ll long long

using namespace std;
const int MN = 300001;
ll dp[MN];

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = -2;
    queue<int> q1, q2;
    ll sum1 = 0, sum2 = 0;
    for(int i = 0; i < queue1.size(); i++) {
        sum1 += queue1[i];
        q1.push(queue1[i]);
        sum2 += queue2[i];
        q2.push(queue2[i]);
    }
    ll sum = (sum1 + sum2) / 2;
    answer = 0;
    for(int i = 0; i < queue1.size() * 3; i++, answer++) {
        if(sum1 == sum2) return answer;
        if(sum1 > sum2) {
            q2.push(q1.front());
            sum1 -= q1.front();
            sum2 += q1.front();
            q1.pop();
        }
        else {
            q1.push(q2.front());
            sum2 -= q2.front();
            sum1 += q2.front();
            q2.pop();
        }
    }
    return -1;
}
#include <bits/stdc++.h>
using namespace std;

bool isPossible(int n, int k, vector<int>& stones) {
    int cnt = 0;
    for(int i = 0; i < stones.size(); i++) {
        if(stones[i] < n) cnt++;
        else cnt = 0;
        if(cnt >= k) return false;
    }
    return true;
}

int solution(vector<int> stones, int k) {
    int left = 0, right = *max_element(stones.begin(), stones.end()) + 1;
    
    while(left + 1 < right) {
        int mid = (left + right) / 2;
        bool ret = isPossible(mid, k, stones);
        if(ret)
            left = mid;
        else
            right = mid;
    }
    
    return left;
}
#include <string>
#include <vector>
#include <iostream>
#define P pair<int,int>

using namespace std;
const int MN = 101;

vector<P> arr;
int sale[4] = {10, 20, 30, 40};
int N;

bool cmp(P a, P b) {
    if(a.first > b.first) return true;
    else if(a.first == b.first && a.second > b.second) return true;
    return false;
}

P dfs(vector<int> v, vector<int>& emoticons) {
    if(v.size() == emoticons.size()) {
        P ret = make_pair(0, 0);
        for(int i = 0; i < N; i++) {
            int price = 0;
            for(int j = 0; j < v.size(); j++) {
                if(v[j] >= arr[i].first)
                    price += (emoticons[j] * (100 - v[j]) / 100);
            }
            if(price >= arr[i].second) ret.first++;
            else ret.second += price;
        }
        return ret;
    }
    vector<int> nxt = v;
    P ret = make_pair(0, 0);
    for(int i = 0; i < 4; i++) {
        nxt.push_back(sale[i]);
        P tmp = dfs(nxt, emoticons);
        if(cmp(tmp, ret))
            ret = tmp;
        nxt.pop_back();
    }

    return ret;
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    N = users.size();
    for(vector<int> v : users)
        arr.push_back(make_pair(v[0], v[1]));
    P rst = dfs(vector<int>(), emoticons);
    answer = {rst.first, rst.second};
    return answer;
}
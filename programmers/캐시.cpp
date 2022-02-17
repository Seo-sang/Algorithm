#include <string>
#include <vector>
#include <cstring>
#include <iostream>

using namespace std;
const int MN = 31;
string cache[MN];
int t[MN];
int N;

int hit(string s) {
    for(int i = 0; i < N; i++)
        if(cache[i] == s)
            return i;
    return -1;
}

int LRU() {
    int idx = 0;
    for(int i = 1; i < N; i++) 
        if(t[idx] > t[i])
            idx = i;
            
    return idx;
}

string modify(string s) {
    string ret = "";
    for(char c : s)
        ret += tolower(c);
    
    return ret;
}

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    memset(t, -1, sizeof(t));
    N = cacheSize;
    for(int i = 0; i < cities.size(); i++) {
        cities[i] = modify(cities[i]);
        int idx = hit(cities[i]);
        if(idx != -1) {
            t[idx] = i;
            answer += 1;
        }
        else {
            idx = LRU();
            cache[idx] = cities[i];
            t[idx] = i;
            answer += 5;
        }
    }
    
    return answer;
}
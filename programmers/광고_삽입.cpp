#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int arr[360000];

int to_int(string str) {
    int h = stoi(str.substr(0, 2));
    int m = stoi(str.substr(3, 2));
    int s = stoi(str.substr(6, 2));
    
    return s + (m * 60) + (h * 3600);
}

string to_str(int n) {
    int h = n / 3600;
    n %= 3600;
    int m = n / 60;
    int s = n % 60;
    
    string hh, mm, ss;
    hh = to_string(h);
    if(h < 10)
        hh = '0' + hh;
    mm = to_string(m);
    if(m < 10)
        mm = '0' + mm;
    ss = to_string(s);
    if(s < 10)
        ss = '0' + ss;
    
    return hh + ':' + mm + ':' + ss;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer;
    
    for(string s : logs) {
        int start = to_int(s.substr(0, 8));
        int end = to_int(s.substr(9));
        
        for(int i = start; i < end; i++) {
            arr[i]++;
        }
    }
    
    int play = to_int(play_time);
    int adv = to_int(adv_time);
    long long mnum = 0;
    int ans = 0;
    long long sum = 0;
    for(int i = 0; i < adv; i++)
        sum += arr[i];
    mnum = sum;
    for(int i = adv; i < play; i++) {
        sum -= arr[i - adv];
        sum += arr[i];
        if(sum > mnum) {
            mnum = sum;
            ans = i - adv + 1;
        }
    }
    answer = to_str(ans);
    
    return answer;
}
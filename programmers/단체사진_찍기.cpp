#include <bits/stdc++.h>

using namespace std;
map<char,int> m;
int pos[8] = {0, 1, 2, 3, 4, 5, 6, 7};

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    int answer = 0;
    m.insert({'A', 0}), m.insert({'C', 1}),
    m.insert({'F', 2}), m.insert({'J', 3}),
    m.insert({'M', 4}), m.insert({'N', 5}),
    m.insert({'R', 6}), m.insert({'T', 7});
    do {
        bool chk = true;
        for(string s : data) {
            int c1 = pos[m[s[0]]];
            int c2 = pos[m[s[2]]];
            int gap = stoi(s.substr(4)) + 1;
            switch(s[3]) {
                case '=':
                    if(abs(c1 - c2) != gap)
                        chk = false;
                    break;
                case '>':
                    if(abs(c1 - c2) <= gap)
                        chk = false;
                    break;
                case '<':
                    if(abs(c1 - c2) >= gap)
                        chk = false;
                    break;
            }
            if(!chk) break;
        }
        if(chk) answer++;
    } while(next_permutation(pos, pos + 8));
    return answer;
}
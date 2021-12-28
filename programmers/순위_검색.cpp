#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

vector<int> db[3][2][2][2];

map<string, int> lan;
map<string, int> work;
map<string, int> career;
map<string, int> food;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    
    lan["cpp"] = 0;
    lan["java"] = 1;
    lan["python"] = 2;
    work["backend"] = 0;
    work["frontend"] = 1;
    career["junior"] = 0;
    career["senior"] = 1;
    food["chicken"] = 0;
    food["pizza"] = 1;
    
    for(string s : info) {
        istringstream iss(s);
        int pos, score;
        string l, w, c, f;
        
        iss >> l >> w >> c >> f >> score;
        
        db[lan[l]][work[w]][career[c]][food[f]].push_back(score);
    }
    
    for(string s : query) {
        int score, cnt = 0;
        string l, w, c, f, tmp;
        istringstream iss(s);
        
        iss >> l >> tmp >> w >> tmp >>c >> tmp >> f >> score;
        
        for(int a = 0; a < 3; a++) {
            if(l == "-" || lan[l] == a) {
                for(int b = 0; b < 2; b++) { 
                    if(w == "-" || work[w] == b) {
                        for(int cc = 0; cc < 2; cc++) {
                            if(c == "-" || career[c] == cc) {
                                for(int d = 0; d < 2; d++) {
                                    if(f == "-" || food[f] == d) {
                                        for(int e : db[a][b][cc][d]) {
                                            if(e >= score)
                                                cnt++;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        answer.push_back(cnt);
    }
    
    
    return answer;
}
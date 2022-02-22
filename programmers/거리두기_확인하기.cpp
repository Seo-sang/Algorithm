#include <string>
#include <vector>
#include <cstring>
#include <stdbool.h>
#include <iostream>

using namespace std;



vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    int di[4] = {1, 0, 0, -1};
    int dj[4] = {0, 1, -1, 0};

    for(vector<string> s : places) {
        int chk = 0;
        for(int i = 0; i < s.size() && !chk; i++) {
            for(int j = 0; j < s[i].size() && !chk; j++) {
                if(s[i][j] == 'P') {
                    for(int d = 0; d < 4 && !chk; d++) {
                        int ni = i + di[d];
                        int nj = j + dj[d];
                        if(ni >= 0 && ni < 5 && nj >= 0 && nj < 5) {
                            if(s[ni][nj] == 'P') {
                                answer.push_back(0);
                                chk = 1;
                                break;
                            }
                            if(s[ni][nj] == 'O') {
                                for(int dd = 0; dd < 4 && !chk; dd++) {
                                    int nni = ni + di[dd];
                                    int nnj = nj + dj[dd];
                                    if(nni == i && nnj == j) continue;
                                    if(nni >= 0 && nni < 5 && nnj >= 0 && nnj < 5) {
                                        if(s[nni][nnj] == 'P') {
                                            answer.push_back(0);
                                            chk = 1;
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        if(!chk) answer.push_back(1);
    }
    return answer;
}
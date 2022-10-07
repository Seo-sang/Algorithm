#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <set>
#define P pair<int,int>

using namespace std;
const int MN = 51;

string board[MN][MN];
int merged[MN][MN];
map<int, set<P>> mergedCells;
map<string, set<P>> valueCells;
int mergeCnt = 1;

vector<string> solution(vector<string> commands) {
    vector<string> answer;
    for(string str : commands) {
        string cmd, a, b, c = "", d = "";
        istringstream iss(str);
        iss >> cmd >> a >> b >> c >> d;
        if(cmd == "UPDATE") {
            if(c == "") {
                for(auto it = valueCells[a].begin(); it != valueCells[a].end(); it++)
                    board[it->first][it->second] = b;
                valueCells[b] = valueCells[a];
                valueCells.erase(a);
            }
            else {
                int row = stoi(a);
                int col = stoi(b);
                string value = c;
                if(merged[row][col] != 0) {
                    for(auto it = mergedCells[merged[row][col]].begin(); it != mergedCells[merged[row][col]].end(); it++) {
                        valueCells[board[it->first][it->second]].erase(make_pair(it->first, it->second));
                        board[it->first][it->second] = value;
                        valueCells[value].insert(make_pair(row, col));
                    }
                }
                else {
                    board[row][col] = value;
                    valueCells[value].insert(make_pair(row, col));
                }
            }
        }
        else if(cmd == "MERGE") {
            int r1 = stoi(a);
            int c1 = stoi(b);
            int r2 = stoi(c);
            int c2 = stoi(d);
            string v = board[r1][c1];
            if(merged[r1][c1] != 0) {
                int mvalue = merged[r1][c1];
                mergedCells[merged[r2][c2]].clear();
                for(int i = min(r1, r2); i <= max(r1, r2); i++) {
                    for(int j = min(c1, c2); j <= max(c1, c2); j++) {
                        merged[i][j] = mvalue;
                        if(board[i][j] != "") {
                            valueCells[board[i][j]].erase({i, j});
                        }
                        board[i][j] = board[r1][c1];
                        valueCells[v].insert({i, j});
                        mergedCells[mvalue].insert({i, j});
                    }
                }
            }
            else if(merged[r2][c2] != 0) {
                int mvalue = merged[r2][c2];
                mergedCells[merged[r1][c1]].clear();
                for(int i = min(r1, r2); i <= max(r1, r2); i++) {
                    for(int j = min(c1, c2); j <= max(c1, c2); j++) {
                        merged[i][j] = mvalue;
                        if(board[i][j] != "") {
                            valueCells[board[i][j]].erase({i, j});
                        }
                        board[i][j] = board[r2][c2];
                        valueCells[v].insert({i, j});
                        mergedCells[mvalue].insert({i, j});
                    }
                }
            }
            else {
                int mvalue = mergeCnt;
                for(int i = min(r1, r2); i <= max(r1, r2); i++) {
                    for(int j = min(c1, c2); j <= max(c1, c2); j++) {
                        merged[i][j] = mvalue;
                        if(board[i][j] != "") {
                            valueCells[board[i][j]].erase({i, j});
                        }
                        board[i][j] = board[r1][c1];
                        valueCells[v].insert({i, j});
                        mergedCells[mvalue].insert({i, j});
                    }
                }
                mergeCnt++;
            }
        }
        else if(cmd == "UNMERGE") {
            int row = stoi(a);
            int col = stoi(b);
            int mvalue = merged[row][col];
            if(mvalue != 0) {
                for(auto it = mergedCells[mvalue].begin(); it != mergedCells[mvalue].end(); it++) {
                    merged[it->first][it->second] = 0;
                    if(row == it->first && col == it->second) continue;
                    board[it->first][it->second] = "";
                }
                mergedCells[mvalue].clear();
            }
        }
        else {
            int row = stoi(a);
            int col = stoi(b);
            answer.push_back((board[row][col] == "") ? "EMPTY" : board[row][col]);
        }
    }

    return answer;
}
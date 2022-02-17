#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

const int MN = 31;
char arr[MN][MN];
char tmp[MN][MN];
bool del[MN][MN];

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    int cnt = 1;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            arr[i][j] = board[i][j];
    
    while(cnt) {
        cnt = 0;
        memset(del, 0, sizeof(del));
        for(int i = 0; i < m - 1; i++) {
            for(int j = 0; j < n - 1; j++) {
                if(arr[i][j] == '.') continue;
                if(arr[i][j] == arr[i][j+1] && arr[i+1][j] == arr[i+1][j+1] && arr[i][j] == arr[i+1][j]) {
                    del[i][j] = 1;
                    del[i+1][j] = 1;
                    del[i][j+1] = 1;
                    del[i+1][j+1] = 1;
                }
            }
        }
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(del[i][j] == 1) {
                    cnt++;
                    arr[i][j] = '.';
                }
            }
        }
        vector<char> v;
        
        fill(&tmp[0][0], &tmp[m-1][n], '.');
        for(int j = 0; j < n; j++) {
            v.clear();
            for(int i = m - 1; i >= 0; i--)
                if(arr[i][j] != '.') 
                    v.push_back(arr[i][j]);
            int idx = m - 1;
            for(int e : v) {
                tmp[idx--][j] = e;
            }
        }
        
        fill(&arr[0][0], &arr[m-1][n], '.');
        
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                arr[i][j] = tmp[i][j];
        
        answer += cnt;
    }
    
    
    return answer;
}
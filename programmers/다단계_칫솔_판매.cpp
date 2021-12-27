#include <string>
#include <vector>
#include <cstring>

using namespace std;

int arr[101][101];
int rotate(int x1, int y1, int x2, int y2) {
    int tmp = arr[x1][y1];
    int rst = tmp;
    for(int i = x1; i < x2; i++) {
        arr[i][y1] = arr[i+1][y1];
        rst = min(rst, arr[i][y1]);
    }
    
    for(int i = y1; i < y2; i++) {
        arr[x2][i] = arr[x2][i+1];
        rst = min(rst, arr[x2][i]);
    }
    
    for(int i = x2; i > x1; i--) {
        arr[i][y2] = arr[i-1][y2];
        rst = min(rst, arr[i][y2]);
    }
    
    for(int i = y2; i > y1; i--) {
        arr[x1][i] = arr[x1][i-1];
        rst = min(rst, arr[x1][i]);
    }
    
    arr[x1][y1+1] = tmp;
    
    return rst;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    memset(arr, 0, sizeof(arr));
    int cnt = 1;
    
    for(int i = 1; i <= rows; i++)
        for(int j = 1; j <= columns; j++) 
            arr[i][j] = cnt++;
    
    for(vector<int> e : queries) {
        answer.push_back(rotate(e[0], e[1], e[2], e[3]));
    }
    
    return answer;
}
#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

const int INF = 2e9;

int dist(int x1, int y1, int x2, int y2) {
    return pow((x1 - x2), 2) + pow((y1 - y2), 2);
}

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    
    for(vector<int> v : balls) {
        int ballX = v[0], ballY = v[1];
        
        double ball, start;
        int up, down, left, right;
        //위쪽 맞추기
        if(startX == ballX && startY < ballY) 
            up = INF;
        else
            up = dist(startX, n + (n - startY), ballX, ballY);
        
        //아래쪽 맞추기
        if(startX == ballX && startY > ballY)
            down = INF;
        else
            down = dist(startX, -startY, ballX, ballY);
        
        //왼쪽 맞추기
        if(startY == ballY && startX > ballX)
            left = INF;
        else
            left = dist(-startX, startY, ballX, ballY);
        
        //오른쪽 맞추기
        if(startY == ballY && startX < ballX)
            right = INF;
        else
            right = dist(m + (m - startX), startY, ballX, ballY);
        
        answer.push_back(min(min(up, down), min(left, right)));
    }
    return answer;
}
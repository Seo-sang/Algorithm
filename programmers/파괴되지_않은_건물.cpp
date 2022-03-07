#include <bits/stdc++.h>

using namespace std;
const int MN = 1001;
int seg[MN][MN * 3];
int lazy[MN][MN * 3];
int answer = 0;

int init(int node, int start ,int end, int row, vector<vector<int>> &board) {
    int mid = (start + end) / 2;
    if(start == end) return seg[row][node] = board[row][start];
    else return seg[row][node] = init(node * 2, start, mid, row, board) + init(node* 2 + 1, mid + 1, end, row, board);
}

void update_lazy(int node, int start, int end, int row) {
    if(lazy[row][node]) {
        seg[row][node] += (end - start + 1) * lazy[row][node];
        
        //리프노드 아닐 경우
        if(start != end) {
            lazy[row][node * 2] += lazy[row][node];
            lazy[row][node * 2 + 1] += lazy[row][node];
        }
        lazy[row][node] = 0;
    }
}

void update(int node, int start, int end, int left, int right, int row, int value) {
    update_lazy(node, start, end, row);
    if(left > end || right < start) return;
    
    if(left <= start && end <= right) {
        seg[row][node] += ((end - start + 1) * value);
        
        if(start != end) {
            lazy[row][node * 2] += value;
            lazy[row][node * 2 + 1] += value;
        }
        return;
    }
    
    int mid = (start + end) / 2;
    update(node * 2, start, mid, left, right, row, value);
    update(node * 2 + 1, mid + 1, end, left, right, row, value);
    
    seg[row][node] = seg[row][node * 2] + seg[row][node * 2 + 1];
    return;
}

void query(int node, int start, int end, int row) {
    update_lazy(node, start, end, row);
    if(start == end) {
        if(seg[row][node] > 0)
            answer++;
    }
    else {
        int mid = (start + end) / 2;
        query(node * 2, start, mid, row);
        query(node * 2 + 1, mid + 1, end, row);
    }
}

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    
    for(int i = 0;  i< board.size(); i++) 
        init(1, 0, board[i].size() - 1, i, board);
    
    for(vector<int> &e : skill) {
        int r1 = e[1], c1 = e[2], r2 = e[3], c2 = e[4];
        int degree = ((e[0] == 1) ? -e[5] : e[5]);
        
        for(int i = r1; i <= r2; i++)
            update(1, 0, board[i].size() - 1, c1, c2, i, degree);
        
    }
    for(int i = 0; i < board.size(); i++)
        query(1, 0, board[0].size() - 1, i);
    
    return answer;
}
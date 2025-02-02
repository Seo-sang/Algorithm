#include <cstring>
#include <list>
#include <queue>
#include <set>
#include <iostream>


const int MW = 200;
const int MH = 200;

int width;
int height;

int board[MW][MH];

int topPos[MW]; //column별로 가장 높은 위치 저장
bool chk[MH][MW];
bool vst[MH][MW];

int score[2];

int dx[8] = {1, -1, 0, 0, 1, -1, 1, -1};
int dy[8] = {0, 0, 1, -1, 1, -1, -1, 1};

int changedx[4] = {1, 0, 0, -1};
int changedy[4] = {0, 1, -1, 0};

std::set<std::pair<int,int> > removed[3];
std::set<int> startPoint;

void init(int W, int H)
{
    width = W;
    height = H;
    memset(board, 0, sizeof(board));
    memset(chk, 0, sizeof(chk));
    memset(vst, 0, sizeof(vst));
    memset(score, 0, sizeof(score));
    memset(topPos, -1, sizeof(topPos));
    startPoint.clear();
    for(int i = 0; i < 3; i++) {
        removed[i].clear();
    }
}
/*
void print_topPos() {
    std::cout << "-----------print topPos---------\n";
    for(int i = 0; i < width; i++) {
        std::cout << topPos[i] << ' ';
    }
    std::cout << std::endl;
    std::cout << "-------------------------\n";

}

void print() {
    std::cout << "-----------print---------\n";

    for(int i = height - 1; i >= 0; i--) {
        for(int j = 0; j < width; j++) {
            //std::cout << topPos[j];
            if(topPos[j] < i) {
                //std::cout << "yes\n";
                std::cout << 0;
            }
            else {
                //std::cout << "no\n";
                std::cout << board[i][j];
            }
        }
        std::cout << std::endl;
    }

    std::cout << "-------------------------\n";
}

void print_chk() {
    std::cout << "-------print_chk---------\n";
    for(int i = height - 1; i >= 0; i--) {
        for(int j = 0; j < width; j++) {
            std::cout << chk[i][j];
        }
        std::cout << std::endl;
    }

    std::cout << "-------------------------\n";
}
*/

void bingo(int mPlayer, int x, int y) {

    // std::cout << "start : " << x << ' ' << y << std::endl;
    if(topPos[y] < x) return;
    int ret = 0;
    std::set<std::pair<int,int> > checked;
    
    for(int d = 0; d < 8; d += 2) {
        // std::cout << "dxdy : " << dx[d] << ' ' << dy[d] << std::endl;
        checked.clear();
        checked.insert(std::make_pair(x, y));
        std::queue<std::pair<int,int> > q;
        q.push(std::make_pair(x, y));
        memset(vst, 0, sizeof(vst));

        while(!q.empty()) {
            std::pair<int,int> now = q.front(); q.pop();

            for(int d2 = d; d2 <= d + 1; d2++) { //양방향으로 탐색
                int nx = now.first + dx[d2];
                int ny = now.second + dy[d2];
                
                if(ny >= 0 && ny < width && nx >= 0 && nx <= topPos[ny]) {
                    if(vst[nx][ny]) continue;
                    // std::cout << "nxny : " << nx << ' ' << ny << std::endl;
                    if(mPlayer == board[nx][ny]) {
                        checked.insert(std::make_pair(nx, ny));
                        q.push(std::make_pair(nx, ny));
                        vst[nx][ny] = true;
                    }
                }
            }
        }

        if(checked.size() >= 5) {
            for(auto it = checked.begin(); it != checked.end(); it++) {
                removed[mPlayer].insert(std::make_pair(it->first,it->second));
                chk[it->first][it->second] = true;
            }
        }
    }

    // std::cout << "size : " << removed.size() << std::endl;

}

void gravity() {
    for(int j = 0; j < width; j++) {
        int removed_cnt = 0;
        for(int i = 0; i <= topPos[j]; i++) {
            if(chk[i][j]) {
                removed_cnt++;
            }
            else {
                board[i - removed_cnt][j] = board[i][j];
            }
        }
        topPos[j] -= removed_cnt;
        if(removed_cnt > 0) {
            startPoint.insert(j);
        }
    }
}

int dropBlocks(int mPlayer, int mCol)
{  
    int ret = 0;
    startPoint.clear();
    memset(chk, 0, sizeof(chk));

    for(int col = mCol; col < mCol + 3; col++) {    //가장 맨 위에 쌓음
        topPos[col]++;
        board[topPos[col]][col] = mPlayer;
    }
    startPoint.insert(mCol);
    startPoint.insert(mCol + 1);
    startPoint.insert(mCol + 2);

    // print_topPos();
    // print();
    while(true) {
        removed[1].clear();
        removed[2].clear();
        memset(chk, 0, sizeof(chk));
        for(auto it = startPoint.begin(); it != startPoint.end(); it++) {
            for(int row = 0; row <= topPos[*it]; row++) {
                bingo(board[row][*it], row, *it);
            }
        }
        // print_chk();
        
        // std::cout <<"removed.size(): " << removed[mPlayer].size() << std::endl;
        gravity();
        // print_topPos();
        // print();
        if(removed[1].size() == 0 && removed[2].size() == 0) break;
        ret += removed[mPlayer].size();
    }
    score[mPlayer-1] += ret;
    // print_topPos();
    // print();

	return ret;
}

int changeBlocks(int mPlayer, int mCol)
{   
    if(topPos[mCol] < 0 || board[0][mCol] == 0 || board[0][mCol] == mPlayer) return 0;
    int ret = 0;
    startPoint.clear();
    memset(chk, 0, sizeof(chk));

    std::queue<std::pair<int,int> > q;
    q.push(std::make_pair(0, mCol));
    board[0][mCol] = mPlayer;

    while(!q.empty()) {
        std::pair<int,int> now = q.front(); q.pop();
        startPoint.insert(now.second);
        for(int d = 0; d < 4; d++) {
            int nx = now.first + changedx[d];
            int ny = now.second + changedy[d];
            if(ny >= 0 && ny < width && nx >= 0 && nx <= topPos[ny]) {
                if(board[nx][ny] != mPlayer) {
                    q.push(std::make_pair(nx, ny));
                    board[nx][ny] = mPlayer;
                }
            }

        }
    }
    // print();
    while(true) {
        removed[1].clear();
        removed[2].clear();
        memset(chk, 0, sizeof(chk));
        for(auto it = startPoint.begin(); it != startPoint.end(); it++) {
            for(int row = 0; row <= topPos[*it]; row++) {
                bingo(board[row][*it], row, *it);
            }
        }
        // print_chk();
        
        // std::cout <<"removed.size(): " << removed[mPlayer].size() << std::endl;
        gravity();
        // print_topPos();
        // print();
        if(removed[1].size() == 0 && removed[2].size() == 0) break;
        ret += removed[mPlayer].size();
    }
    // print_topPos();
    // print();

    score[mPlayer-1] += ret;
	return ret;
}


int getResult(int mBlockCnt[2])
{   
    mBlockCnt[0] = 0;
    mBlockCnt[1] = 0;
    for(int j = 0; j < width; j++) {
        for(int i = 0; i <= topPos[j]; i++) {
            if(board[i][j] == 1) mBlockCnt[0]++;
            else if(board[i][j] == 2) mBlockCnt[1]++;
        }
    }
    
    // std::cout << "final remain blocks: " << mBlockCnt[0] << ' ' << mBlockCnt[1] << std::endl;
    // std::cout << "final score: " << score[0] << ' ' << score[1] << std::endl;
    if(score[0] > score[1]) return 1;
    else if (score[0] < score[1]) return 2;
    else return 0;
}

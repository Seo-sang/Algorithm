#include <bits/stdc++.h>

using namespace std;
const int MN = 201;
deque<pair<int,int>> belt;

int main() {
    int N, K; cin >> N >> K;
    for(int i = 1; i <= N * 2 ; i++) {
        int a; cin >> a;
        belt.push_back({a, 0});
    }
    
    int ans = 1;
    int cnt = 0;
    int p = 0;
    while(true) {
        //rotate
        belt.push_front(belt.back());
        belt.pop_back();
        //N위치 내리기
        belt[N-1].second = 0;

        //회전방향으로 한칸씩 이동
        for(int i = N - 2; i > 0; i--) {
            if(belt[i].second == 1 && belt[i+1].second == 0 && belt[i + 1].first > 0) {
                belt[i+1].first--;
                if(belt[i + 1].first == 0) cnt++;
                belt[i].second = 0;
                belt[i+1].second = 1;
            }
        }
        belt[N-1].second = 0;

        //1번 위치에 올리기
        if(belt[0].first > 0) {
            belt[0].first--;
            if(belt[0].first == 0) cnt++;
            belt[0].second = 1;
        }

        if(cnt >= K) break;
        
        ans++;
    }
    cout << ans;
}
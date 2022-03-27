#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int MN = 11;
ll arr[MN];
ll ans;
int N, M;
ll K;
vector<int> history;
void dfs(int now, ll money, ll cnt, ll loan) {
    ll tmp, tmploan, tmpcnt;
    //cout << now <<"번째 날 : " << money << "원 " << cnt << "개 " << loan << "원 "<<  endl;
    if(now == N - 1) {
        //cout << money << ' ' << cnt << ' ' << loan << endl;
        if(money + cnt * arr[now] == 2352000) {
            // for(int e : history)
            //     cout << e << ' ';
            // cout << endl;
        }
        ans = max(ans, money + cnt * arr[now]);
        return;
    }

    /*매도하고 매수하는 경우*/
    if(cnt > 0) {
        //매도
        tmp = money + cnt * arr[now];
        if(tmp > loan) {
            //대출금 갚고
            tmp -= loan;

            //빌리고
            tmploan = tmp * K;
            tmp += tmploan;

            //매수
            if(tmp >= arr[now]) {
                tmpcnt = tmp / arr[now];
                tmp -= tmpcnt * arr[now];
                history.push_back(100 + now);
                dfs(now + 1, tmp, tmpcnt, tmploan);
                history.pop_back();
            }
        }
    }


    /*매도 안하고 매수하는 경우*/
    //대출금 갚고
    if(money > loan) {
        tmp = money - loan;
        //대출
        tmploan = tmp * K;
        tmp += tmploan;
        //매수할 수 있을 때
        if(arr[now] <= tmp) {
            int tmpcnt = tmp / arr[now];
            tmp -= tmpcnt * arr[now];
            history.push_back(200 + now);
            dfs(now + 1, tmp, tmpcnt + cnt, tmploan);
            history.pop_back();
        }
    }

    /*매도하고 매수 안하는 경우*/
    //매도
    if(cnt > 0) {
        tmp = money + cnt * arr[now];
        history.push_back(300 + now);
        dfs(now + 1, tmp, 0, loan);
        history.pop_back();
    }

    /*매도 안하고 매수 안하는 경우*/
    history.push_back(400 + now);
    dfs(now + 1, money, cnt, loan);
    history.pop_back();
}

int main() {
     cin >> N >> M >> K;
    for(int i = 0; i < N; i++)
        cin >> arr[i];

    dfs(0, M, 0, 0);
    cout << ans;
}
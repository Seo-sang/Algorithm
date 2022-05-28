#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#define ll long long
using namespace std;

const int INF = 1e9;
const int MN = 1e6 + 1;

int f(int mid, int power, int distance) {
    double tmp = (double)mid * power;
    if(tmp * tmp - ((double)2 * power * distance) < 0) return MN;
    int ret1 = ceil((tmp + sqrt((tmp * tmp) - ((double)2 * power * distance))) / power);
    int ret2 = ceil((tmp - sqrt((tmp * tmp) - ((double)2 * power * distance))) / power);
    if(ret2 < 0) return ret1;
    else if(ret2 < ret1) return ret2;
    else return ret1;
}

int solution(int fuel, vector<int> powers, vector<int> distances) {
    int answer = INF;
    int left = 0, right = MN;
    while(left + 1 < right) {
        int mid = (left + right) / 2;
        int ret = 0;
        for(int i = 0; i < powers.size(); i++) {
            int tmp = f(mid, powers[i], distances[i]);
            ret += tmp;
            if(ret > fuel) break;
        }
        if(ret <= fuel)
            right = mid;
        else
            left = mid;
    }
    return right;
}
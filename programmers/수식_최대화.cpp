#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

#define ll long long

using namespace std;

char op[4] = {'+', '-', '*', '/'};
int idx[4] = {0, 1, 2, 3};

vector<ll> num;
vector<char> ope;
vector<ll> numst;
vector<char> opst;

long long solution(string expression) {
    long long answer = 0;
    
    string s = "";
    for(char c : expression) {
        if(isdigit(c))
            s += c;
        else {
            num.push_back(stoll(s));
            s = "";
            ope.push_back(c);
        }
    }
    
    num.push_back(stoll(s));
    
    do {
        vector<ll> tmp1;
        vector<char> tmp2;
        numst = num;
        opst = ope;
        for(int i = 0; i < 4; i++) {
            tmp1.clear(), tmp2.clear();
            for(int j = 0; j < opst.size(); j++) {
                if(tmp1.empty()) {
                    tmp1.push_back(numst[j]);
                    tmp2.push_back(opst[j]);
                }
                else if(tmp2.back() == op[idx[i]]) {
                    ll n1;
                    switch(tmp2.back()) {
                        case '+':
                            n1 = tmp1.back() + numst[j]; tmp1.pop_back();
                            tmp1.push_back(n1);
                            break;
                        case '-':
                            n1 = tmp1.back() - numst[j]; tmp1.pop_back();
                            tmp1.push_back(n1);
                            break;
                        case '*':
                            n1 = tmp1.back() * numst[j]; tmp1.pop_back();
                            tmp1.push_back(n1);
                            break;
                        case '/':
                            n1 = tmp1.back() / numst[j]; tmp1.pop_back();
                            tmp1.push_back(n1);
                            break;
                    }
                    tmp2.pop_back();
                    tmp2.push_back(opst[j]);
                }
                else {
                    tmp1.push_back(numst[j]);
                    tmp2.push_back(opst[j]);
                }
            }
            if(tmp1.empty())
                tmp1.push_back(numst.back());
            else if(tmp2.back() == op[idx[i]]) {
                ll n1;
                switch(tmp2.back()) {
                    case '+':
                        n1 = tmp1.back() + numst.back(); tmp1.pop_back();
                        tmp1.push_back(n1);
                        break;
                    case '-':
                        n1 = tmp1.back() - numst.back(); tmp1.pop_back();
                        tmp1.push_back(n1);
                        break;
                    case '*':
                        n1 = tmp1.back() * numst.back(); tmp1.pop_back();
                        tmp1.push_back(n1);
                        break;
                    case '/':
                        n1 = tmp1.back() / numst.back(); tmp1.pop_back();
                        tmp1.push_back(n1);
                        break;
                }
                tmp2.pop_back();
            }
            else
                tmp1.push_back(numst.back());
                
            numst = tmp1;
            opst = tmp2;
        }
        answer = max(answer, abs(numst.back()));
        
    } while(next_permutation(idx, idx + 4));
    
    return answer;
}
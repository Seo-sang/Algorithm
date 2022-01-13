#include <iostream>
#include <list>
using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    int T; cin >> T;
    list<char> ls;
    while(T--) {
        string s; cin >> s;
        ls.clear();
        auto it = ls.end();
        for(char c : s) {
            switch(c) {
                case '<':
                    if(it != ls.begin()) it--;
                    break;
                case '>':
                    if(it != ls.end()) it++;
                    break;
                case '-':
                    if(it != ls.begin()) {
                        it--;
                        it = ls.erase(it);
                    }
                    break;
                default:
                    if(it == ls.end()) {
                        ls.push_back(c);
                        it = ls.end();
                    }
                    else {
                        it = ls.insert(it, c);
                        it++;
                    }
                    break;
            }
        }
        while(!ls.empty()) {
            cout << ls.front();
            ls.pop_front();
        }
        cout << '\n';
    }
}
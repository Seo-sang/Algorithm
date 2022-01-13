#include <iostream>
#include <list>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL);
    string str; cin >> str;
    list<char> ls;
    for(char c : str)
        ls.push_back(c);
    auto it = ls.end();
    int M; cin >> M;
    while(M--) {
        char c; cin >> c;
        switch(c) {
            case 'L':
                if(it != ls.begin()) it--;
                break;
            case 'D':
                if(it != ls.end()) it++;
                break;
            case 'B':
                if(it != ls.begin()) {
                    it--;
                    it = ls.erase(it);
                }
                break;
            case 'P':
                char add; cin >> add;
                if(it == ls.end()) {
                    ls.push_back(add);
                    it = ls.end();
                }
                else {
                    ls.insert(it, add);
                }
                break;
        }
    }
    while(!ls.empty()) {
        cout << ls.front();
        ls.pop_front();
    }
}
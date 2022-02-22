#include <bits/stdc++.h>

using namespace std;
multiset<int> s;

int main() {
    s.insert(10);
    s.insert(13);
    s.insert(14);
    auto it = s.begin();
    // it++;
    // it++;
    // it++;
    it++;
    s.erase(10);
    if(it == s.end())
        it--;
    cout << *it << endl;
}
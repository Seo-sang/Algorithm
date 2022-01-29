#include <bits/stdc++.h>

using namespace std;
multiset<int> s;

int main() {
    s.insert(10);
    s.insert(13);
    s.insert(13);
    auto it = s.begin();
    it++;
    it++;
    it--;
    cout << *it << endl;
}
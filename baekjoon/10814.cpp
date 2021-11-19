#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct edge {
    int seq, age;
    string name;
};

vector<edge> arr;

bool cmp(edge a, edge b) {
    if(a.age == b.age) return a.seq < b.seq;
    return a.age < b.age;
}

int main() {
    int N; cin >> N;
    int age;
    string name;
    for(int i = 0; i < N; i++) {
        cin >> age >> name;
        arr.push_back({i, age, name});
    }

    sort(arr.begin(), arr.end(), cmp);

    for(int i = 0; i < N; i++)
        cout << arr[i].age << ' ' << arr[i].name << '\n';
}
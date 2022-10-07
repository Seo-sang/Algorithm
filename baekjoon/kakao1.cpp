#include <string>
#include <vector>
#include <map>

using namespace std;

map<char, int> due;

string change(string str, int num) {
    int year = stoi(str.substr(0, 4));
    int month = stoi(str.substr(5, 2)) + num;
    int date = stoi(str.substr(8, 2)) - 1;

    if(date < 1) {
        date = 28;
        month--;
    }
    if(month > 12) {
        year += (month / 12);
        month %= 12;
    }
    if(month < 1) {
        month = 12;
        year--;
    }
    string ret = to_string(year) + '.';
    if(month < 10) ret += '0';
    ret += to_string(month) + '.';
    if(date < 10) ret += '0';
    ret += to_string(date);

    return ret;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    for(string str : terms) {
        due[str[0]] = stoi(str.substr(2));
    }
    for(int i = 0; i < privacies.size(); i++) {
        string str = privacies[i];
        char c = str.back();
        string ret = change(str.substr(0, 10), due[c]);
        if(ret < today) answer.push_back(i + 1);
    }

    return answer;
}
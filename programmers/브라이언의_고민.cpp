#include <bits/stdc++.h>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
bool vst[27];

string solution(string sentence) {
    memset(vst, 0, sizeof(vst));
    string answer = "";
    
    for(int i = 0; i < sentence.size(); i++) {
        string word = "";
        char c = sentence[i];
    
        if(islower(c)) { //rule 1
            if(vst[c - 'a']) return "invalid";
            int pos = sentence.substr(i + 1).find(c);
            string tmp = sentence.substr(i + 1, pos);
            i += pos + 1;
            //rule 2
            char pivot = '0';
            int j = 0;
            for(; j < tmp.size(); j++) {
                if(islower(tmp[j])) {
                    if(j % 2 == 0)
                        return "invalid";
                    if(pivot == '0')
                        pivot = tmp[j];
                    else if(pivot != tmp[j])
                        return "invalid";
                }
                else
                    word += tmp[j];
            }
            if(pivot != '0')
                vst[pivot] = true;
            answer = answer + ' ' + word;
            cout << "1 : " << word << endl;
        }
        else {
            i++;
            while(i < sentence.size() && isupper(sentence[i])) {
                word += sentence[i - 1];
                answer = answer + ' ' + word;
                word = "";
                i++;
            }
            i--;
            int j = 0;
            char pivot = '0';
            //"AA ABA BBBB C BBBB C BB GG GGG RRRRRR"
            for(; i + j < sentence.size(); j++) {
                if(islower(sentence[i + j])) {
                    if(vst[sentence[i + j] - 'a'] || j % 2 == 0)
                        return "invalid";
                    if(pivot == '0') {
                        pivot = sentence[i + j];
                    }
                    else if(pivot != sentence[i + j])
                        break;
                }
                else {
                    if(j % 2 == 0)
                        word += sentence[i + j];
                    else
                        break;
                }
            }
            i += (j - 1);
            if(pivot != '0')
                vst[pivot] = true;
            if(word != "")
                answer = answer + ' ' + word;
            cout << "3 : " << word << endl;
        }
        vst[c - 'a'] = true;
    }
    
    
    return answer.substr(1);
}
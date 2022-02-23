#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;
struct node {
    node *prev;
    int value;
    node *next;
};
node *head, *tail, *list;

stack<node *> st;

string solution(int n, int k, vector<string> cmd) {
    string answer = "";
    vector<bool> vst(n);
    list = new node;
    list->value = 0;
    list->prev = NULL;
    list->next = NULL;
    head = tail = list;
    node *now, *del;
    
    for(int i = 1; i < n; i++) {
        node* input = new node;
        input->value = i;
        input->prev = tail;
        input->next = NULL;
        tail->next = input;
        tail = tail->next;
        if(k == i)
            now = tail;
    }
    
    for(string str : cmd) {
        int num;
        switch(str[0]) {
            case 'U':
                num = stoi(str.substr(2));
                while(num--)
                    now = now->prev;
                break;
            case 'D':
                num = stoi(str.substr(2));
                while(num--)
                    now = now->next;
                break;
            case 'C':
                st.push(now);
                del = now;
                if(del == tail) {
                    now = now->prev;
                    now->next = NULL;
                    tail = now;
                }
                else {
                    now = now->next;
                    if(del == head) {
                        head = now;
                        now->prev = NULL;
                    }
                    else {
                        del->prev->next = del->next;
                        del->next->prev = del->prev;
                    }
                }
                break;
            case 'Z':
                del = st.top(); st.pop();
                if(del->prev != NULL) {
                    del->prev->next = del;
                    if(del->prev == tail)
                        tail = del;
                }
                if(del->next != NULL) {
                    del->next->prev = del;
                    if(del->next == head)
                        head = del;
                }
                break;
        }
    }
    
    node *it = head;
    while(it != NULL) {
        vst[it->value] = true;
        it = it->next;
    }
    
    for(int i = 0; i < n; i++) {
        if(vst[i])
            answer += 'O';
        else
            answer += 'X';
    }
            
    
    return answer;
}
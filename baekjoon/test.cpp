#include <iostream>
#include <vector>
using namespace std;
int N; 
vector<int> v;
int find(int num){
    if(num<0) num = -num;
    int mid;
    int low = 0; int high = N-1;
    while(low+1<high){
        mid = (low+high)/2;
        //printf("low: %d, mid: %d, high: %d, num: %d\n",low,mid,high,num);
        if(num > v[mid]) low = mid;
        else high = mid;
    }
    return high;
}
int main(){
    int a,b;
    cin>>N;
    for(int i = 0; i<N; i++){
        int num; cin>>num;
        v.push_back(num);
    }
    int temp = 2e9+1;
    for(int i = 0; i<N; i++){
        int j = find(v[i]);
        cout << i << ' ' << j << endl;
        if(i==j){
            if(j==0) j++;
            else if(j==N-1) j--;
            else{
                if(abs(v[j+1]+v[i])<abs(v[j-1]+v[i])) j++;
                else j--;
            }
        }
        int value = v[j]+v[i];
        //printf("v[i]: %d, v[j]: %d, value: %d, temp: %d\n", v[i],v[j],value,temp);
        if(abs(value)<abs(temp)){
            a = v[j];
            b = v[i];
            temp = value;
        }
        
    }
    
    if(abs(v[N/2]+v[N/2-1])<abs(temp)){
        a = v[N/2];
        b = v[N/2-1];
        temp = v[N/2]+v[N/2-1];
    }
    
    if(N==2){
        a = v[0];
        b = v[1];
    }
    
    if(a>b) swap(a,b);
    cout<<a<<" "<<b;
}
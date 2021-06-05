#include <iostream>
#include <vector>
#include <map>

using namespace std;
int f1(int n, int m, vector<int> &l){

}

int f(int n, int m , vector<int> &l){
    if(n == 0 ) return 0;
    
    map<int, int> count;
    vector<int> pre(n);
    pre[0] = l[0]%m;
    for(int i=1;i<n;i++){
        pre[i] = (l[i]+pre[i-1])%m;
    }
    for(int i=0;i<n;i++){
        if(count.find(pre[i]) == count.end()){
            count[i] = 1;
        }else count[pre[i]] += 1;
    }
    int res  = 0;
    auto ptr=count.begin();
    auto end = count.end();
    for(;ptr!=end;ptr++){
        res += ptr->second*(ptr->second-1)/2;
        if(ptr->first == 0){
            res += 1;
        }
    }
    return res;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<int> l(n);
    int t;
    for(int i=0;i<n;i++){
        cin>> t;
        l[i] = t;
    }
    auto res = f(n, m, l);
    cout<<res;
    return 0;
}

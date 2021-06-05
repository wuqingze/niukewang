#include <iostream>
#include <vector>

using namespace std;

int f(int n, int m, vector<int> &l){
    vector<int> count(m, 0);
    count[0] = 1;
    vector<int> pre(n);
    int res = 0;
    pre[0] = l[0]%m;
    res += count[pre[0]];
    count[pre[0]] += 1;
    for(int i=1;i<n;i++){
        pre[i] = (pre[i-1]+l[i]%m)%m;
        res += count[pre[i]];
        count[pre[i]] += 1;
    }
    return res;
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<int> l(n);
    for(int i=0;i<n;i++){
        cin>>l[i];
    }
    auto res = f(n, m, l);
    cout<<res<<endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int f(int n, vector<int> &l){
    sort(l.begin(), l.end());
    int cnt=0;
    for(int i=0;i<n;i++){
        if(l[i]<i+1){
            cnt += (i+1-l[i]);
        }else{
            cnt += (l[i] - (i+1));
        }
    }
    return cnt;
}

int main(){
    int n;
    cin>>n;
    vector<int> l(n);
    int t;
    for(int i=0;i<n;i++){
        cin>>t;
        l[i] = t;
    }
    cout<<f(n, l)<<endl;
    return 0;
}

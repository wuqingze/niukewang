#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int f(int n, int x, int y, vector<int> &l){
    sort(l.begin(), l.end());
    int i=0;
    while(i<n){
        while(i<n-1 and l[i]==l[i+1]) i+=1;
        int low = i+1;
        int hight = n-i-1;
        if((low>=x and low<=y) and (hight>=x and hight<=y)) return l[i];
        i += 1;
    }
    return -1;
}

int main(){
    int n,x,y;
    cin>>n>>x>>y;
    vector<int> l(n);
    int t;
    for(int i=0;i<n;i++){
        cin>>t;
        l[i] = t;
    }
    cout<<f(n, x, y, l)<<endl;
    return 0;
}

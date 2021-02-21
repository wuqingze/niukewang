#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

vector<int> f(int n, const vector<int> &l,
        int m, const vector<int> &q){
    return {};
}

int main(){
    int n;
    cin>>n;
    int t = pow(2, n);
    vector<int> l;
    while(t-->0 and cin>>n) 
        l.push_back(n);
    int m;
    cin>>m;
    vector<int> q;
    while(m-->0 and cin>>t) q.push_back(t);

    auto ret = f(l.size(), l, q.size(), q);
    for(auto i:ret) cout<<i<<endl;
    return 0;
}

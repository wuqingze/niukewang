#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

int f(int n, string &s1, string &s2){
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    int res = 0;
    for(int i=0;i<n;i++){
        res += abs(s1[i]-s2[i]);
    }
    return res;
}

int main(){
    int n;
    cin>> n;
    string s1, s2;
    cin>>s1>>s2;
    auto res = f(n, s1, s2);
    cout<<res<<endl;
    return 0;
}

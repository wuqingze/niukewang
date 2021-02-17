#include <iostream>
using namespace std;
int main(){
    int cnt;
    cin>>cnt;
    while(cnt-->0){
        string s;
        cin>>s;
        int i=0;
        int n = s.size();
        string ret = "";
        int j=0;
        while(i<n){
            if(i==n-1) {
                ret += s[i];
                break;
            }
            if(s[i] != s[i+1]){
                ret += s[i];
                j += 1;
                i += 1;
            }else if(s[i] == s[i+1]){
                if(j>1 and ret[j-1] == ret[j-2]){
                    ret += s[i];
                    i += 1;
                    j += 1;
                    while(i<n and s[i-1] == s[i])  i++;
                }else{
                    ret += s[i];
                    ret += s[i];
                    i += 1;
                    j += 2;
                    while(i<n and s[i] == s[i-1])  i++;
                }
            }
        }
        cout<<ret<<endl;
    }
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;

string f(string s){
    int n = s.size();
    if(n<3) return s;
    vector<char> vec(n, '\0');
    int j=0;
    int i=0;
    while(i<n){
        int c=0;
        while(i+c<n && s[i] == s[i+c]) c++;
        if(c==1) vec[j++] = s[i];
        else if(j-2>=0 && vec[j-1] == vec[j-2]) vec[j++] = s[i];
        else {vec[j++]=s[i]; vec[j++] = s[i];}
        i += c;
    }
    string ret="";
    for(int i=0; i<j;i++) ret+=vec[i];
    return ret;
}

int main(){
    int c=0;
    string line;
    while(getline(cin, line)){
        if(c==0) { c+=1; continue;}
        cout<<f(line)<<endl;
    }
    return 0;
}

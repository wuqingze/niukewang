#include <iostream>
#include <vector>

using namespace std;

string f(string s){
    int n = s.size();
    if(n<3) return s;
    
    int i=0, j=0;
    vector<char> vec(n, '\0');
    while(i<n){
        int c=0;
        while(i+c<n && s[i] == s[i+c]) c++;
        if(c>1){
            if(j-2>=0 && s[j-1] == s[j-2]) vec[j++] = s[i];
            else { vec[j++] = s[i]; vec[j++] = s[i];}
        }else{
            vec[j++] = s[i];
        }
        i += c;
    }
    string ret;
    for(i=0;i<j;i++) ret += vec[i];
    return ret;
}

int main(){
    int c=0;
    string line;
    while(getline(cin, line)){
        if(c==0){ c++; continue;}
        cout<<f(line)<<endl;
    }
    return 0;
}

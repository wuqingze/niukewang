#include <iostream>
#include <vector>

using namespace std;

struct V{
    bool isNum;
    int num;
    string str;
    V(bool in_, int num_, string s):
        isNum(in_), num(num_), str(s){}
};

string nstr(int n, const string &str){
    string ret = "";
    while(n-->0) ret += str;
    return ret;
}

string f(string &s){
    int n = s.size();
    if(n==0) return "";

    vector<V> l;
    int i=0;
    int j=0;
    while(i<n and j<n){
        if('[' == s[j]){
            l.push_back(V(false, 0, s.substr(i, j-i)));
            i = j+1;
            j = i;
        }else if(']' == s[j]){
            string tstr = s.substr(i,j-i);
            while(not l.back().isNum){
                auto item = l.back();
                tstr = item.str + tstr;
                l.pop_back();
            }
            auto item = l.back();
            tstr = nstr(item.num, tstr);
            l.pop_back();
            if(tstr.size()>0){
                l.push_back(V(false, 0, tstr));
            }
            i = j+1;
            j = i;
        }else if('|' == s[j]){
            l.push_back(V(true, std::stoi(s.substr(i, j-i)), ""));
            i = j+1;
            j = i;
        }else{
            j += 1;
            if(j>n-1)
                l.push_back(V(false, 0, s.substr(i, i-j)));
        }
    }
    string ret = "";
    for(auto item:l) ret += item.str;
    string tstr = "BHCJSBCSCWDASKDNKJWDNWCNQWCNOQCNQWOICNWQOINCWQOICNQWOIXWOISWIODAOWPQWDMQKOQZCDWFDASKDNKJWDNWCNQWCNOQCNQWOICNWQOINCWQOICNQWOIXWOISWIODAOWPQWDMQKOQZCDWFDASKDNKJWDNWCNQWCNOQCNQWOICNWQOINCWQOICNQWOIXWOISWIODAOWPQWDMQKOQZCDWFDASKDNKJWDNWCNQWCNOQCNQWOICNWQOINCWQOICNQWOIXWOISWIODAOWPQWDMQKOQZCDWFDASKDNKJWDNWCNQWCNOQCNQWOICNWQOINCWQOICNQWOIXWOISWIODAOWPQWDMQKOQZCDWFDASKDNKJWDNWCNQWCNOQCNQWOICNWQOINCWQOICNQWOIXWOISWIODAOWPQWDMQKOQZCDWFDASKDNKJWDNWCNQWCNOQCNQWOICNWQOINCWQOICNQWOIXWOISWIODAOWPQWDMQKOQZCDWFDASKDNKJWDNWCNQWCNOQCNQWOICNWQOINCWQOICNQWOIXWOISWIODAOWPQWDMQKOQZCDWFDASKDNKJWDNWCNQWCNOQCNQWOICNWQOINCWQOICNQWOIXWOISWIODAOWPQWDMQKOQZCDWFDASKDNKJWDNWCNQWCNOQCNQWOICNWQOINCWQOICNQWOIXWOISWIODAOWPQWDMQKOQZCDWFDASKDNKJWDNWCNQWCNOQCNQWOICNWQOINCWQOICNQWOIXWOISWIODAOWPQWDMQKOQZCDWFDASKDNKJWDNWCNQWCNOQCNQWOICNWQOINCWQOICNQWOIXWOISWIODAOWPQWDMQKOQZCDWFDAS";
    for(int i=0;i<tstr.size();i++){
        if(ret[i] != tstr[i]){
            cout<<i<<endl;
            cout<<tstr.substr(0,i+1);
            cout<<ret.substr(0,i+1);
            exit(1);
        }
    }
    return ret;
}

int main(){
    string s;
    cin>>s;
    cout<<f(s)<<endl;
    return 0;
}

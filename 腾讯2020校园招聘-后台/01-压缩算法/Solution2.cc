#include <iostream>
#include <vector>

using namespace std;

struct Node{
    bool isNum;
    int num;
    string val;
    Node(bool isNum_, int num_, string val_):
        isNum(isNum_), num(num_), val(val_){}
};

string nstr(int n, const string &s){
    string ret = "";
    while(n-->0) ret += s;
    return ret;
}

string f(const string &s){
    int n = s.size();
    if(n == 0) return "";
    vector<Node> l;
    int i=0, j=0;
    while(i<n){
        if(s[j] == '['){
            l.push_back(Node(false, 0, s.substr(i, j-i)));
            j += 1;
            i = j;
        }else if(s[j] == '|'){
            l.push_back(Node(true, stoi(s.substr(i, j-i)), ""));
            j += 1;
            i = j;
        }else if(s[j] == ']'){
            string temp = s.substr(i, j-i);
            while(not l.back().isNum){
                temp = l.back().val + temp;
                l.pop_back();
            }
            temp = nstr(l.back().num, temp);
            l.pop_back();
            l.push_back(Node(false, 0, temp));
            j += 1;
            i = j;
        }else{
            j += 1;
            if(j == n){
                l.push_back(Node(false, 0, s.substr(i, j-i)));
                i = j;
            }
        }
    }
    string ret = "";
    for(auto item:l) ret += item.val;
    return ret;
}

int main(){
    string s;
    cin>>s;
    cout<<f(s)<<endl;
    return 0;
}

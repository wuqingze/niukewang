#include <iostream>
#include <set>

using namespace std;
bool compare(string &s1, string &s2) { return s2<s1;}

string f(string &s, int k){
    int n = s.size();
    auto cmp = [](const string &s1, const string &s2) { return s2<s1; };
    set<string, decltype(cmp)> count(cmp);
    int cnt =0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            string t = s.substr(i, j-i+1);
            if(count.find(t) == count.end()){
                if(cnt == k){
                    if(t<*(count.begin())){
                        count.erase(count.begin());
                        count.insert(t);
                    }
                }else{
                    count.insert(t);
                    cnt += 1;
                }
            }
        }
    }
    return *(count.begin());
}

int main(){
    string s;
    cin>>s;
    int k;
    cin>>k;
    auto res = f(s, k);
    cout<<res<<endl;
    return 0;
}

#include <iostream>
#include <vector>
#include <set>

using namespace std;

void f(int N, string &table, int M, string &line){
    set<int> l0;
    set<int> l1;
    vector<int> ret;
    for(int i=0;i<N;i++){
        if(table[i] == '0') l0.insert(i);
        else if(table[i] == '1') l1.insert(i);
    }
    for(auto c:line){
        if(l1.empty() and l0.empty()) return;
        if('M' == c){
            if(l1.empty()){
                int t = *(l0.cbegin());
                std::printf("%d\n", t+1);
                l0.erase(t);
                l1.insert(t);
            }else{
                int t = *(l1.cbegin());
                std::printf("%d\n", t+1);
                l1.erase(t);
            }
        }else{
            if(l0.empty()){
                int t = *(l1.cbegin());
                std::printf("%d\n", t+1);
                l1.erase(t);
            }else{
                int t = *(l0.cbegin());
                std::printf("%d\n", t+1);
                l0.erase(t);
                l1.insert(t);
            }
        }
    }
}

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int T;
    cin>>T;
    while(T-->0){
        int N;
        cin>>N;
        string table;
        cin>>table;
        int M;
        cin>>M;
        string line;
        cin>>line;
        f(N, table, M, line);
    }
    return 0;
}


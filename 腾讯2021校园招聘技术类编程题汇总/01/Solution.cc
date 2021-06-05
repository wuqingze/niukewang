#include <iostream>
#include <vector>
#include <map>

using namespace std;
class UF{
public:    
    vector<int> root;
    vector<int> rank;
    UF(int n){
        root = vector<int>(n+1);
        rank = vector<int>(n+1, 1);
        for(int i=0;i<=n+1;i++) root[i] = i;
    }
    
    int find(int i){
        if(root[i] == i) return i;
        root[i] = find(root[i]);
        return root[i];
    }
    
    void merge(int i, int j){
        int ir = find(i);
        int jr = find(j);
        if(rank[ir]<=rank[jr]){
            root[ir] = jr;
        }else{
            root[jr] = ir;
        }
        if(rank[ir] == rank[jr]){
            rank[jr] += 1;
        }
    }
    
    int mx(){
        int n = root.size();
        vector<int> count(n, 0);
        int res = 0;
        for(int i=0;i<n;i++){
            int r = find(i);
            count[r] += 1;
            res = max(count[r], res);
        }
        return res;
    }
};

int f(int n, vector<pair<int, int>> &l){
    UF uf(10000001);
    for(int i=0;i<n;i++){
        uf.merge(l[i].first, l[i].second);
    }
    return uf.mx();
}

int main(){
    int m;
    cin>>m;
    while(m-->0){
        int n;
        cin>>n;
        vector<pair<int,int>> l(n);
        for(int i=0;i<n;i++){
            cin>>l[i].first;
            cin>>l[i].second;
        }
        auto res = f(n, l);
        cout<<res<<endl;
    }
    return 0;
}

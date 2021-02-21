#include <iostream>
#include <vector>

using namespace std;

enum DIRECTION{
    LEFT, RIGHT
};

vector<pair<int, int>> monotoneStack(const vector<int> &l, DIRECTION direction){
    int n = l.size();
    if(n==0) return {};
    auto ret = vector<pair<int, int>>(n, {-1,1});
    if(direction == DIRECTION::LEFT){
        for(int i=1;i<n;i++){
            int j = i-1;
            while(j!=-1 and l[j]<=l[i]){
                j = ret[j].first;
            }
            if(j != -1){
                ret[i].first = j;
                ret[i].second = ret[j].second + 1;
            }
        }
    }else{
        for(int i=n-2;i>=0;i--){
            int j = i +1;
            while(j!=-1 and l[j]<=l[i])
                j = ret[j].first;
            if(j!=-1){
                ret[i].first = j;
                ret[i].second = ret[j].second +1;
            }
        }
    }
    return ret;
}

vector<int> f(const vector<int> l){
    int n = l.size();
    if(n==0) return {};
    auto lms = monotoneStack(l, DIRECTION::LEFT);
    auto rms = monotoneStack(l, DIRECTION::RIGHT);
    auto ret = vector<int>(n,0);
    for(int i=0;i<n;i++){
        int lh = i==0?0:lms[i-1].second;
        int rh = i==n-1?0:rms[i+1].second;
        ret[i] = lh+rh+1;
    }
    return ret;
}

int main(){
    int n ;
    cin>>n;
    vector<int> l;
    int i;
    while(n-->0 and cin>>i) l.push_back(i);
    auto ret = f(l);
    for(auto i:ret) cout<<i<<" ";
    cout<<endl;
    return 0;
}

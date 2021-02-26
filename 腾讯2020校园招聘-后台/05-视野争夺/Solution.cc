#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int f(int n, int L, vector<pair<int, int>> &l){
    if(n==0) return -1;
    sort(l.begin(), l.end(), 
            [](const auto &o1, const auto &o2){
                return o1.first<o2.first;
            }
        );
    pair<int, int> zone = {0,0};
    int i=0;
    int cnt = 0;
    while(i<n){
        auto maxzone = l[i];
        while(i<n and l[i].first <= zone.second){
            if(l[i].second > maxzone.second)
                maxzone = l[i];
            i+=1;
        }
        if(maxzone.first > zone.second) return -1;
        if(zone.second < maxzone.second){
            zone.second = maxzone.second;
            cnt += 1;
        }
    }
    if(zone.second < L) return -1;
    return cnt;
}

int main(){
    int n;
    cin>>n;
    int L;
    cin>>L;
    vector<pair<int,int>> l(n);
    int t0,t1;
    for(int i=0;i<n;i++){
        cin>>t0>>t1;
        l[i] = {t0, t1};
    }
    cout<<f(n, L, l)<<endl;
    return 0;
}

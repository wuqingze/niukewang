#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

vector<int> getVec(map<int,int> &tmap){
    vector<int> ret;
    auto ptr = tmap.begin();
    while(ptr != tmap.end()){
        int k = ptr->first;
        int v= ptr->second;
        while(v-->0) ret.push_back(k);
        ptr ++;
    }
    sort(ret.begin(), ret.end());
    return ret;
}

bool check(vector<int> nums){
    int n = nums.size();
    if(n<3) return true;
    if(n==3) return (nums[0]==nums[1] && nums[1] == nums[2]) || (nums[0] + 1==nums[1] && nums[1]+1 == nums[2]);

    map<int, int> tmap;
    for(auto c:nums) tmap[c] = tmap.count(c)?tmap[c]+1:1;

    auto ptr = tmap.begin();
    int k=ptr->first;
    int v=ptr->second;
    bool ret = false;
    if(tmap.count(k+1) && tmap.count(k+2)){
        tmap[k] -= 1;
        tmap[k+1] -= 1;
        tmap[k+2] -= 1;
        ret = check(getVec(tmap));
        if(ret) return true;
        tmap[k] += 1;
        tmap[k+1] += 1;
        tmap[k+2] += 1;
    }
    if(tmap.count(k-1) && tmap.count(k+1)){
        tmap[k] -= 1;
        tmap[k-1] -= 1;
        tmap[k+1] -= 1;
        ret = check(getVec(tmap));
        if(ret) return true;
        tmap[k] += 1;
        tmap[k-1] += 1;
        tmap[k+1] += 1;
    }
    if(tmap.count(k-2) && tmap.count(k-1)){
        tmap[k] -= 1;
        tmap[k-1] -= 1;
        tmap[k-2] -= 1;
        ret = check(getVec(tmap));
        if(ret) return true;
        tmap[k] += 1;
        tmap[k-1] += 1;
        tmap[k-2] += 1;
    }

    if(tmap[k] == 3){
        tmap[k] -= 3;
        ret = check(getVec(tmap));
        if(ret) return true;
    }else{
        return false;
    }
    return true;
}

vector<int> f(vector<int> & nums){
    map<int, int> tmap;
    vector<int> ret;
    for(auto c:nums) if(tmap.count(c)) tmap[c]+=1; else tmap[c] = 1;
    for(int i=1;i<=9;i++){
        if(tmap.count(i) && tmap[i] == 4) continue;
        tmap[i] = tmap.count(i)?tmap[i]+1:1;
        auto ptr = tmap.begin();
        while(ptr != tmap.end()){
            int k = ptr->first;
            int v = ptr->second;
            if(v>=2){
                tmap[k] -= 2;
                auto list = getVec(tmap);
                if(check(list)) {ret.push_back(i); break;};
                tmap[k] += 2;
            }
            ptr ++;
        }
        tmap[i] -= 1;
    }
    return ret;
}

int main(){
    vector<int> nums;
    int n;
    while(cin>>n) nums.push_back(n);
    auto ret = f(nums);
    for(auto c: ret) cout<<c<<" ";
    return 0;
}

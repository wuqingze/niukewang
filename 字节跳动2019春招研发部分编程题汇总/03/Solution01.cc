#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> list(map<int, int> tmap){
    vector<int> ret;
    auto ptr = tmap.begin();
    while(ptr != tmap.end()){
        int v = tmap[ptr->first];
        while(v-->0) ret.push_back(ptr->first);
        ptr ++;
    }
    return ret;
}

bool check(vector<int> nums){
    int n = nums.size();
    if(n<3) return false;
    if(n==3) return (nums[0] == nums[1] && nums[1] == nums[2]) || (nums[0]+1 == nums[1] && nums[1]+1 == nums[2]);
    
    map<int, int> tmap;
    for(auto c:nums) tmap[c] = tmap.find(c) !=tmap.end()?tmap[c]+1:1;
   
    int k=tmap.begin()->first;
    int v=tmap.begin()->second;
    bool ret = false;
    if(tmap.find(k+1)!=tmap.end() && tmap.find(k+2) != tmap.end()){
        tmap[k] -= 1;
        tmap[k+1] -= 1;
        tmap[k+2] -= 1;
        ret = check(list(tmap));
        if(ret) return true;
        tmap[k] += 1;
        tmap[k+1] += 1;
        tmap[k+2] += 1;
    }
    if(tmap.find(k-1)!=tmap.end() && tmap.find(k+1) != tmap.end()){
        tmap[k] -= 1;
        tmap[k-1] -= 1;
        tmap[k+1] -= 1;
        ret = check(list(tmap));
        if(ret) return true;
        tmap[k] += 1;
        tmap[k-1] += 1;
        tmap[k+1] += 1;
    }
    if(tmap.find(k-1) !=tmap.end() && tmap.find(k-2) != tmap.end()){
        tmap[k] -= 1;
        tmap[k-1] -= 1;
        tmap[k-2] -= 1;
        ret = check(list(tmap));
        if(ret) return true;
        tmap[k] += 1;
        tmap[k-1] += 1;
        tmap[k-2] += 1;
    }
    if(tmap[k] == 3){
        tmap[k] -= 3;
        return check(list(tmap));
    }else return false;
    return ret;
}

vector<int> f(vector<int> &nums){
    vector<int> ret;
    map<int, int> tmap;
    for(auto c:nums) tmap[c] = tmap.count(c)?tmap[c]+1:1;
    for(int i=1;i<=9; i++){
        if(tmap.find(i)!=tmap.end() && tmap[i] == 4) continue;
        tmap[i] = tmap.find(i) != tmap.end()?tmap[i]+1:1;
        auto ptr = tmap.begin();
        while(ptr != tmap.end()){
            int k = ptr->first;
            int v = ptr->second;
            if(v>=2){
                tmap[k] -= 2;
                bool t = check(list(tmap));
                tmap[k] += 2;
                if(t){ ret.push_back(i); break;}
            }
            ptr++;
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
    if(ret.size() == 0) cout<<0<<endl;
    else for(auto c:ret) cout<<c<<" ";
    return 0;
}

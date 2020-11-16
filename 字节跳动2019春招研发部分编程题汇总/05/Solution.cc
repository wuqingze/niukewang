#include <iostream>
#include <vector>
using namespace std;

bool find(vector<int> &nums, int target){
    for(auto c:nums) if(c== target) return true;
    return false;
}

void foo(int i, int n, vector<vector<int>> &nums, vector<int> &dp, int count, int &min){
    if(dp.size() == n-1){
        count += nums[i][0];
        min = min<count?min:count;
        return;
    }
    
    dp.push_back(i);
    for(int j=0;j<n;j++){
        if(j!=i && !find(dp, j)){
            foo(j, n, nums, dp, count+nums[i][j], min);
        }
    }
    dp.pop_back();
}

int f(int n, vector<vector<int>> &nums){
    int ret = 20000;
    vector<int> dp;
    foo(0, n, nums, dp, 0, ret);
    return ret;
}

int main(){
    int n;cin>>n;
    vector<vector<int>> nums(n, vector<int>(n, 0));
    int t;
    for(int i=0;i<n; i++) for(int j=0;j<n;j++) {cin>>t; nums[i][j] = t;}
    auto ret = f(n, nums);
    cout<<ret<<endl;
    return 0;
}

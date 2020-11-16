#include <iostream>
#include <vector>
#include <set>

using namespace std;

int f(int n, vector<vector<int>> &nums){
    set<int> tset;
    int i=0;
    int ret =0;
    tset.insert(0);
    while(tset.size()<n){
        int k=0;
        int mn=1000;
        for(int j=0;j<n;j++){
            if(i!=j && tset.find(j) == tset.end() && mn>nums[i][j]){
                k = j;
                mn = nums[i][j];
            }
        }
        tset.insert(k);
        i = k;
        ret += mn;
    }
    ret += nums[i][0];
    return ret;
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> nums(n, vector<int>(n, 0));
    int t;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) { cin>>t;nums[i][j]=t;}
    auto ret = f(n, nums);
    cout<<ret<<endl;
    return 0;
}

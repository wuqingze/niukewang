#include <iostream>
#include <vector>

using namespace std;

int binary(int i, int j, vector<int> &nums, int target){
    while(i<j){
        int mid = i+(j-i)/2;
        if(nums[mid] == target) return mid;
        else if(nums[mid]<target) i=mid+1;
        else j=mid-1;
    }
    if(nums[i]<=target) return i;
    else return i-1;
}

int f(int n, int k, vector<int> &nums){
    int i=0;
    int ret = 0;
    for(int i=0; i<n-2;i++){
        int j = binary(i+1, n-1, nums, nums[i]+k);
        int c = j-i;
        if(c>1){
            ret += (c*(c-1))/2%99997867;
        }
    }
    return ret;
}

int main(){
    int n,k;
    cin>>n>>k;
    int i;
    vector<int> nums;
    while(cin>>i) nums.push_back(i);
    cout<<f(n, k, nums)<<endl;
}

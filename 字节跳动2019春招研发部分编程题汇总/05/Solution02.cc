#include <iostream>
#include <vector>
#include <set>

using namespace std;

int f(int n, vector<vector<int>> &nums){
    int ret = 200000;
    set<int> tset;
    for(int i=0;i<n;i++){
        tset.clear();
        tset.insert(i);
        int tret = 0;
        int k=i;
        while(tset.size()<n){
            cout<<k<<" ";
            int mn=1000;
            int l =-1;
            bool flag = false;
            for(int j=0;j<n;j++){
                if(tset.find(j) == tset.end() && mn>nums[k][j]){
                    l = j;
                    mn = nums[k][j];
                    flag = true;
                }
            }
            tset.insert(l);
            k =l;
            tret += flag?mn:0;
        }
        cout<<k<<" ";
        tret += nums[k][i];
        cout<<"--"<<tret<<endl;
        ret = ret<tret?ret:tret;
    }
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

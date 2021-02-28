#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

enum STATUS{
    NONE, WORKING, EXERCISING
};

int maxdays(int i, int n, STATUS pre, vector<int> &working, 
        vector<int> &exercising, vector<vector<int>> &dp){
    if(i>=n) return 0;
    if(dp[i][pre] != -1) return dp[i][pre];
    if(days[i] == 0){
        dp[i][pre] = maxdays(i+1, n, STATUS::NONE, working, exercising, dp);
    }else{
        if(pre == STATUS::WORKING){
            dp[i][pre] = maxdays(i+1, n, STATUS::NONE, days, dp);
        }else if(pre == STATUS::ONE){
            dp[i][pre] = std::max({
                    maxdays(i+1, n, STATUS::NONE, days, dp),
                    maxdays(i+1, n, STATUS::TWO, days, dp) + 1 
                    }
                    );
        }else if(pre == STATUS::NONE){
            dp[i][pre] = std::max({
                    maxdays(i+1, n, STATUS::NONE, days, dp),
                    maxdays(i+1, n, STATUS::ONE, days, dp)+1
                    });
        }
    }
    return dp[i][pre];
}

int f(int n, vector<int> &days){
    if(n==0) return 0;
    vector<vector<int>> dp(n, {-1,-1,-1});
    int mdays = maxdays(0,n, STATUS::NONE, days,dp); 
    return n-mdays;
}

int main(){
    int n;
    cin>>n;
    int t;
    vector<int> days(n);
    for(int i=0;i<n;i++){
        cin>>t;
        days[i] = t;
    }
    for(int i=0;i<n;i++){
        cin>>t;
        days[i] |= t;
    }
    cout<<f(n, days)<<endl;
}


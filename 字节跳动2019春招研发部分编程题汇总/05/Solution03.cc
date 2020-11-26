#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Cities{
    public:
        int len;
        int count=0;
        vector<int> cities;
        Cities(int n){
            len = n;
            cities = vector<int>(n, 0);
        }

        string getkey(int i, int j){
            string ret = intToStr(i)+intToStr(j);
            for(int i=0;i<len; i++) if(cities[i] == 0) ret += ("-"+intToStr(i));
            return ret;
        }

        void set(int i){
            if(i>=0 && i<len && cities[i] == 0){
                cities[i] = 1;
                count += 1;
            }
        }

        void unset(int i){
            if(i>=0 && i<len && cities[i] == 1){
                cities[i] = 0;
                count -= 1;
            }
        }

        int getunset(){
            for(int i=0;i<len;i++) if(cities[i]==0) return i;
            return -1;
        }

        bool isdone(){
            return len == count;
        }

        vector<int> getunsets(){
            vector<int> ret;
            for(int i=0;i<len; i++) if(cities[i] == 0) ret.push_back(i);
            return ret;
        }

     private:
        string intToStr(int n){
            string ret="";
            do{
                int t=n%10;
                ret += '0'+t;
                n  = n/10;
            }while(n);
            int i=0,j=ret.size()-1;
            while(i<j){
                char c = ret[i];
                ret[i] = ret[j];
                ret[j] = c;
                i++;
                j--;
            }
            return ret;
        }
};

int foo(int n, vector<vector<int>> &nums, Cities &cities, map<string, int> &dp, int i, int j){
    if(cities.isdone()){
        return nums[i][j];
    }

    string key = cities.getkey(i, j);
    if(dp.find(key) != dp.end()) return dp[key];
    int mn = 1000000;
    for(auto c:cities.getunsets()){
        cities.set(c);
        int t = foo(n, nums, cities, dp, c, j)+nums[i][c];
        mn = mn<t?mn:t;
        cities.unset(c);
    }
    dp[key] = mn;
    return dp[key];
} 

int f(int n, vector<vector<int>> &nums){
    int ret = 10000000;
    Cities cities(n);
    map<string, int> dp;
    for(int i=0;i<n;i++){
        cities.set(i);
        int t = foo(n, nums, cities, dp, i, i);
        ret = ret<t?ret:t;
        cities.unset(i);
    }
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

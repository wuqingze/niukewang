#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

void f(int a1, vector<int>&arr, vector<string>& result, int i, int n){
    if(i==n-1){
        string t = "1"+to_string(a1);
        for(int j=0;j<n;j++){
            t += to_string(arr[j]);
        }
        result.push_back(t);
        return;
    }
    for(int j=i;j<n;j++){
        swap(arr[i], arr[j]);
        f(a1, arr, result, i+1, n);
        swap(arr[i], arr[j]);
    }
}


vector<string> groups(){
    vector<string> res;
    for(int i=2;i<=6;i++){
        vector<int> t;
        for(int j=2;j<=6;j++){
            if(j!=i){
                t.push_back(j);
            }
        }
        f(i, t, res, 1, 4);
    }
    return res;
}

string arrtostring(vector<int> &l){
    string res = "";
    for(int i=0;i<l.size();i++){
        res += to_string(l[i]);
    }
    return res;
}

void shift(vector<int> &l){
    int n = l.size();
    int mn = 0;
    for(int i=0;i<n;i++){
        if(l[i]< l[mn]) mn = i;
    }
    if(mn == 0){
        return;
    } else if(mn == 1){
        swap(l[0], l[1]);
        swap(l[2], l[3]);
    } else if(mn == 2){
        int t = l[0];
        l[0] = l[2];
        l[2] = l[1];
        l[1] = l[3];
        l[3] = t;
    } else if(mn == 3){
        int t = l[0];
        l[0] = l[3];
        l[3] = l[1];
        l[1] = l[2];
        l[2] = t;
    }
}

string key(vector<int> &l){
    int i,j;
    if(l[0] == 1){
    }else if(l[1] == 1){
        swap(l[0], l[1]);
        swap(l[4], l[5]);
    } else if(l[2] == 1){
        int t = l[0];
        l[0] = l[2];
        l[2] = l[1];
        l[1] = l[3];
        l[3] = t;
    } else if(l[3] == 1){
        int t = l[0];
        l[0] = l[3];
        l[3] = l[1];
        l[1] = l[2];
        l[2] = t;
    } else if(l[4] == 1){
        int t = l[0];
        l[0] = l[4];
        l[4] = l[1];
        l[1] = l[5];
        l[5] = t;
    } else if(l[5] == 1){
        int t = l[0];
        l[0] = l[5];
        l[5] = l[1];
        l[1] = l[4];
        l[4] = t;
    }
    vector<int> arr(4);
    for(int i=2;i<6;i++) arr[i-2] = l[i];
    shift(arr);
    for(int i=2;i<6;i++) l[i] = arr[i-2];
    return arrtostring(l);
}

void f(int n, vector<vector<int>> &l){
    map<string, int> count;
    for(int i=0;i<n;i++){
        string k = key(l[i]);
        if(count.find(k) == count.end()) count[k] = 1;
        else count[k] += 1;
    }
    cout<<count.size()<<endl;
    vector<int> tl;
    for(auto ptr=count.begin();ptr!=count.end();ptr++){
        tl.push_back(ptr->second);
    }
    sort(tl.begin(), tl.end(), [](auto &o1, auto &o2){ return o1>o2;});
    for(auto &i:tl) cout<<i<<" ";
    cout<<endl;
}

int main(){
    int n;
    cin>>n;
    vector<vector<int>> l(n, vector<int>(6,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<6;j++) cin>>l[i][j];
    }
    f(n, l);
    return 0;
}

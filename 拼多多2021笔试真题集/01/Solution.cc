#include <vector>
#include <iostream>

using namespace std;

bool f1(vector<bool> &l, int cnt, int target){
    for(int i=9;i>0;i--){
        if(not l[i]){
            if(i+cnt == target){
                l[i] = true;
                return true;
            }else if(i + cnt > target){
                continue;
            }else{
                l[i] = true;
                auto t = f1(l, cnt+i, target);
                if(t) return true;
                else{
                    l[i] = false;
                    continue;
                }
            }
        }else continue;
    }
    return false;
}

int f(int n){
    vector<bool> l(10, false);
    auto t = f1(l, 0, n);
    int pow = 1;
    int res = 0;
    if(t){
        for(int i=9;i>0;i--){
            if(l[i]){
                res += i*pow;
                pow *= 10;
            }
        }
        return res;
    }else{
        return -1;
    }
}

int main(){

    int n;
    cin>>n;
    auto res = f(n);
    cout<<res<<endl;
    return 0;
}

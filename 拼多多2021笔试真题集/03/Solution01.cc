#include <iostream>
#include <cstring>
using namespace std;
int main(){
    int n, m;
    cin>>n>>m;
    int arr[n];
    for (int i = 0; i < n; ++i){
        cin>>arr[i];
    }
    int map[m];//下标表示前缀和 % m后的值，map[i]表示取余后值为i的个数；
    memset(map, 0, sizeof(map));
    map[0] = 1;//需要设置这个初始值，看下面代码就懂了
    long sum = 0;
    long ans = 0;
    for (int i = 0; i < n; ++i){
        sum += arr[i];
        int index = sum % m;
        ans += map[index]++;
    }
    cout<<ans<<endl;
    return 0;
}

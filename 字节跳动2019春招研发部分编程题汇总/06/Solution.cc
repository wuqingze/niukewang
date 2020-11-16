#include <iostream>

using namespace std;

int f(int n){
    int arr[4] = {64, 16, 4, 1};
    int ret=0;
    int i=0;
    while(n){
        while(i<4 && arr[i]>n)  i++;
        ret += n/arr[i];
        n = n%arr[i];
    }
    return ret;
}

int main(){
    int n;
    cin>>n;
    cout<<f(n)<<endl;
}

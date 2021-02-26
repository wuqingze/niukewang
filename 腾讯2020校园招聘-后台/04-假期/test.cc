#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
enum T{
    one, two, three
};

int f(){
    return 1;
}
int main(){
    vector<int> arr = {1,2,3};
    cout<<T::one<<endl;
    cout<<T::two<<endl;
    cout<<T::three<<endl;
    cout<<arr[T::one]<<endl;
    return 0;

    cout<<std::max({
            1,2
            });
    return 0;
}

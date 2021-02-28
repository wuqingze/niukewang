#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main(){
    set<int> s;
    s.insert(3);
    s.insert(2);
    s.insert(1);
    int a = *(s.cbegin());
    cout<<a<<endl;
    s.erase(a);

    a = *(s.cbegin());
    cout<<a<<endl;
    s.erase(a);

    a = *(s.cbegin());
    cout<<a<<endl;

    return 0;
}

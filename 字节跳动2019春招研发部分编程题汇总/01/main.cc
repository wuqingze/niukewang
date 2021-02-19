#include <iostream>
#include <vector>

using namespace std;

int main(){
    auto i = std::stoi("1024");
    i += 1;
    std::printf("%d\n", i);
    auto s = std::to_string(i);
    std::printf("%s\n", s.c_str());
    s = std::to_string(3.1415925);
    std::printf("%s\n", s.c_str());
    s = "0123456789";
    cout<<s.substr(1,3)<<endl;
    return 0;
}

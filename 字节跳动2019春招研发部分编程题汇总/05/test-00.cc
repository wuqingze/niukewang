#include <iostream>
#include <vector>
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

        string getkey(int n){
            string ret = intToStr(n);
            for(int i=0;i<len; i++) if(cities[i] == 0) ret += ("-"+intToStr(i));
            return ret;
        }

        void set(int i){
            if(i>=0 && i<len && cities[i] == 0){
                cities[i] == 1;
                count += 1;
            }
        }

        void unset(int i){
            if(i>=0 && i<len && cities[i] == 1){
                cities[i] = 0;
                count -= 1;
            }
        }

        bool isdone(){
            return len == count;
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

int main(){
    auto c = Cities(10);
    cout<<c.getkey(0);
    return 0;
}



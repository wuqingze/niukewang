#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

void reverse(vector<int> &l, int i, int j){
    while(i<j){
        int t = l[i];
        l[i] = l[j];
        l[j] = t;
        i += 1;
        j -= 1;
    }
}

void reverse(int gap, vector<int> &l){
    int i=0;
    int n = l.size();
    while(i<n){
        int j = i+gap-1<n?i+gap-1:n-1;
        reverse(l, i, j);
        i = j+1;
    }
}

int merge(vector<int> &list, int i, int j, int k, int l){
    int cnt = 0;
    vector<int> t;
    int p1=i;
    int p2=k;
    while(p1<=j and p2<=l){
        if(list[p1]<=list[p2]){
            t.push_back(list[p1]);
            cnt += p2-k;
            p1 +=1;
        }else{
            t.push_back(list[p2]);
            p2 += 1;
        }
    }
    if(p1<=j){
        while(p1<=j){
            cnt += (l-k+1);
            t.push_back(list[p1++]);
        }
    }
    if(p2<=l){
        while(p2<=l)
            t.push_back(list[p2++]);
    }
    for(int m=0;m<l-i+1;m++){
        list[i+m] = t[m];
    }
    return cnt;
}

int reversedSequencePairNum(vector<int> &l){
    int n = l.size();
    if(n ==0) return 0;
    int gap = 2;
    int cnt = 0;
    while(gap<2*n){
        int i = 0;
        while(i<n){
            int j = i+gap/2-1<n?i+gap/2-1:n-1;
            int k = j+1;
            int l_ = i+gap-1<n?i+gap-1:n-1;
            if(k<n){
                cnt += merge(l, i, j, k, l_);
            }
            i += gap;
        }
        gap *= 2;
    }
    return cnt;
}

vector<int> f(int n, vector<int> &l,
        int m, const vector<int> &q){
    if(n==0) return {};
    vector<int> ret;
    for(auto gap:q){
        reverse(gap, l);
        auto copy = vector<int>(l);
        ret.push_back(reversedSequencePairNum(copy));
    }
    return ret;
}

int main(){
    int n;
    cin>>n;
    int t = pow(2, n);
    vector<int> l;
    while(t-->0 and cin>>n) 
        l.push_back(n);
    int m;
    cin>>m;
    vector<int> q;
    while(m-->0 and cin>>t) q.push_back(pow(2,t));

    auto ret = f(l.size(), l, q.size(), q);
    for(auto i:ret) cout<<i<<endl;
    return 0;
}

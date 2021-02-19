#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int getAns(vector<vector<int>> &nums){
    const int MAX = 0x0fffffff;
    int n = nums.size();
    int stateNum = 1 << n;
    // dp[i][j]�е�i��һ����������ʽ��������ʾ�������еļ��ϣ���0111��ʾ�����˳���0,1,2
    // dp[i][j]��ʾ������i�еĳ��У�������j��β��·������
    vector<vector<int> > dp(stateNum,vector<int>(n,MAX));
    dp[1][0] = 0; //�ӳ���0���������Ծ�������0���Գ���0��β��·��Ϊ0
    //�ӳ���0���������º��������еľ���
    for(int i=1;i<stateNum;i++){
        for(int j=0;j<n;j++){
            if(dp[i][j] != MAX){ //����Ѿ����ʹ�
                for(int k=0;k<n;k++){
                    if( (i & (1 << k) ) == 0){ 
                        //û�з��ʹ�k���Ҵ����ﵽk�ľ���С��ԭ���ľ��룬�����
                        dp[i | (1 << k)][k] = min(dp[i | (1 << k)][k],dp[i][j] + nums[j][k]);
                    }
                }
            }
        }
    }
    int res = MAX;
    for(int i=1;i<n;i++){
        res = min(res,dp[stateNum-1][i] + nums[i][0]);
    }
    return res;
}
int main(int argc, char const *argv[])
{
   int n;
    while(cin>>n){
        vector<vector<int>> edges(n,vector<int>(n,0));
        int x;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cin>>edges[i][j];
            }
        }
        cout<<getAns(edges)<<endl;
    }
    return 0;
}


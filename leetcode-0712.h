#include "utils.h"
// *两个字符串删除到相同的最小ASCLL值和
class Solution {
    string s1;
    string s2;
    int size1;
    int size2;
    vector<vector<int>> memo;
public:
    int minimumDeleteSum(string s1, string s2) {
        this->s1 = s1;
        this->s2 = s2;
        size1 = s1.size();
        size2 = s2.size();
        memo = vector<vector<int>>(size1+1, vector<int>(size2+1,-1));
        return traceback(0,0);
    }
    //-从前往后递归,dp的意义为到p1和p2为止的最小删除和
    int traceback(int p1,int p2){
        if(memo[p1][p2]!=-1){
            return memo[p1][p2];
        }
        if(p1==size1){
            int temp = 0;
            for(int i = p2;i<size2;++i){
                temp+=(int)s2[i];
            }
            memo[p1][p2] = temp;
            return memo[p1][p2];
        }
        if(p2==size2){
            int temp = 0;
            for(int i = p1;i<size1;++i){
                temp+=(int)s1[i];
            }
            memo[p1][p2] = temp;
            return memo[p1][p2];
        }

        //-两个字符相等,不用删
        if(s1[p1] == s2[p2]){
            memo[p1][p2] = traceback(p1+1,p2+1);
            return memo[p1][p2];
        }
        //-不相等，尝试删除任意一个字符
        else{
            int res1 = (int)s1[p1]+traceback(p1+1,p2);
            int res2 = (int)s2[p2]+traceback(p1,p2+1);
            memo[p1][p2] = min(res1,res2);
            return memo[p1][p2];
        }
    }
};
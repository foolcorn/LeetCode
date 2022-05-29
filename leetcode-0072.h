#include "utils.h"
// *编辑距离：返回将word1转换到word2的最少操作数
// *操作可以是：插入，删除，替换
class Solution {
private:
    vector<vector<int>> memo;
public:
    int minDistance(string word1, string word2) {
        int p1 = word1.size();
        int p2 = word2.size();
        memo = vector<vector<int>>(p1+1,vector<int>(p2+1,-1));
        return sonProblem(word1,word2,p1-1,p2-1);
    }
    int sonProblem(string &word1, string &word2, int p1, int p2){
        if(memo[p1+1][p2+1]!=-1){
            return memo[p1+1][p2+1];
        }
        //-如果p1和p2一起走完
        if(p1 == -1&&p2 == -1){
            memo[p1+1][p2+1] = 0;
            return 0;
        }
        //-如果p2走完，p1还没有走完,删除剩余的p1
        if(p2 == -1&&p1>-1){
            memo[p1+1][p2+1] = p1+1;
            return p1+1;
        }
        //-如果p1走完，p2还没有走完，在p1前插入剩余的p2
        if(p1 == -1&&p2>-1){
            memo[p1+1][p2+1] = p2+1;
            return p2+1;
        }
        char c1 = word1[p1];
        char c2 = word2[p2];
        //-字符相等不用操作
        if(c1 == c2){
            memo[p1+1][p2+1] = sonProblem(word1,word2,p1-1,p2-1);
            return memo[p1+1][p2+1];
        }
        //-字符不等，做选择
        //-如果c1替换c2
        int res1 = 1 + sonProblem(word1,word2,p1-1,p2-1);
        //-如果删掉c1
        int res2 = 1 + sonProblem(word1,word2,p1-1, p2);
        //-如果插入一个和c2一样的值
        int res3 = 1 + sonProblem(word1,word2,p1, p2-1);
        memo[p1+1][p2+1] = min(res1,min(res2,res3));
        return memo[p1+1][p2+1];
    }
};
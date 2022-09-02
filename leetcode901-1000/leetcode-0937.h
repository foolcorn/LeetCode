#include "utils.h"
// *给定日志logs，有两种不同类型的日志：
// ***字母日志：除标识符之外，所有字均由小写字母组成
// ***数字日志：除标识符之外，所有字均由数字组成
// *请按下述规则将日志重新排序：
// ***所有 字母日志 都排在 数字日志 之前。
// ***字母日志 在内容不同时，忽略标识符后，按内容字母顺序排序；在内容相同时，按标识符排序。
// ***数字日志 应该保留原来的相对顺序。
// *返回日志的最终顺序。
class Solution {
public:
    static bool cmpLet (string s1, string s2){
        int index1 = (int)s1.find(' ');
        string head1 = s1.substr(0,index1);
        string temp1 = s1.substr(index1+1);
        int index2 = (int)s2.find(' ');
        string head2 = s2.substr(0,index2);
        string temp2 = s2.substr(index2+1);
        if(temp1 == temp2){
            return head1<head2;
        }
        return temp1<temp2;
    }
    vector<string> reorderLogFiles(vector<string> logs) {
        //-先区分数字和字母
        vector<string> lets;
        vector<string> nums;
        for(auto &ele:logs){
            int index = (int)ele.find(' ');
            char c = ele[index+1];
            if(isdigit(c)){
                nums.push_back(ele);
            }else{
                lets.push_back(ele);
            }

        }
        //-给字母类型排序
        sort(lets.begin(),lets.end(),cmpLet);
        //-数字接在字母后面
        lets.insert(lets.end(),nums.begin(),nums.end());
        return lets;
    }
};
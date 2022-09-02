#include "utils.h"
// *电话号码的字母组合
class Solution {
    vector<string> res;
    vector<string> mmap;
    string digits;
    int size;
public:
    //-思路，这种问题就类似梦幻西游，给六个装备栏装备武器，每个装备栏只能装备特定的身体部位的饰品
    vector<string> letterCombinations(string digits) {
        this->digits = digits;
        if(digits.empty()){return res;}
        size = (int)digits.size();
        mmap = vector<string>()={"0","0","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string path;
        traceback(path,0);
        return res;
    }
    //-对于这种组合型的子集问题，设一个index作为递归参数，代表目前已经装备到第几个装备栏了。
    void traceback(string& path,int num_index){
        if(num_index == size){
            res.push_back(path);
            return;
        }

        string temp = mmap[digits[num_index]-'0'];
        for(int i = 0;i<temp.size();++i){
            path.push_back(temp[i]);
            traceback(path,num_index+1);
            path.pop_back();
        }
    }
};
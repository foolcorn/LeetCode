#include "utils.h"
// *电话号码的字母组合
class Solution {
    vector<string> res;
    vector<string> mmap;
    string digits;
    int size;
public:
    vector<string> letterCombinations(string digits) {
        this->digits = digits;
        if(digits.empty()){return res;}
        size = (int)digits.size();
        mmap = vector<string>()={"0","0","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string path;
        traceback(path,0);
        return res;
    }
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
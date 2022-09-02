#include "utils.h"
// * 标签验证器，没啥意义这一题，不用看
class Solution {
public:
    bool isValid(string code) {
        int p = 0;
        int size = (int)code.size();
        vector<string> temp;//-检查标签闭合。
        //-0 左标签内只允许大写字母
        //-3 右标签内只允许大写字母
        //-1 data内允许任意字符
        //-2 非标签模式
        int sign = -1;
        int tempindex = 0;
        while(p!=size){
            cout<<code[p]<<" ";
            if(sign == -1 && code[p] == '<' && p+1<size && code[p+1]!='/' && code[p+1]!='!'){
                tempindex = p;
                sign = 0;
                ++p;
                continue;
            }
            if(sign == 2 && code[p] == '<' && p+1<size && code[p+1]!='/' && code[p+1]!='!'){
                tempindex = p;
                sign = 0;
                ++p;
                continue;
            }
            if(sign == 0 && code[p] == '>'){
                if(p-tempindex<=1||p-tempindex>=11){
                    return false;
                }
                if(temp.empty()&&tempindex!=0){
                    return false;
                }
                temp.push_back(code.substr(tempindex,p-tempindex+1));
                sign = 2;
                ++p;
                continue;
            }
            // cout<<code.substr(p,9)<<endl;
            if(sign == 2 && code.substr(p,9) == "<![CDATA["){
                cout<<"![CDATA[";
                sign = 1;
                p+=9;
                continue;
            }
            if(sign == 1 && code.substr(p,3)=="]]>"){
                sign = 2;
                p+=3;
                continue;
            }
            if(sign == 2 && code.substr(p,2) == "<!"){
                return false;
            }
            if(sign == 2 && code[p] == '<' && p+1<size && code[p+1] == '/'){
                tempindex = p;
                sign = 3;
                p+=2;
                continue;
            }
            if(sign == 3 && code[p] == '>'){
                string left = temp.back().substr(1);
                temp.pop_back();
                string right = code.substr(tempindex+2,p-tempindex-1);
                if(left!=right){
                    return false;
                }
                sign = 2;
                ++p;
                if(temp.empty()){
                    break;
                }
                continue;
            }
            if(sign == 0 && !isupper(code[p])){
                return false;
            }
            if(sign == 3 && !isupper(code[p])){
                return false;
            }
            ++p;
        }
        if(p==size&&sign == 2&&temp.empty()){
            return true;
        }else{
            return false;
        }

    }
};
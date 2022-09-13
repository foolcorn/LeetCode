#include "utils.h"
// *24点游戏
class Solution {
private:
    double epsilon = 1e-6;
    int target = 24;
    vector<char> operators={'+','*','-','/'};
public:
    bool judgePoint24(vector<int>& cards) {
        //-先把所有的卡牌转成double型
        vector<double> cards_copy;
        for (int i=0; i<cards.size(); ++i){
            cards_copy.push_back((double)cards[i]);
        }
        return judgeVec(cards_copy);
    }

    bool judgeVec(vector<double>& cards) {
        //-如果无元素则返回false
        if(cards.size() == 0){
            return false;
        }
        //-如果只剩一个元素了，判断和target的距离
        if(cards.size() == 1){
            return fabs(cards[0]-target)<epsilon;
        }
        for(int i=0; i<cards.size(); ++i){
            for (int j = 0; j <cards.size();++j){
                if(i!=j){
                    //-建立一个临时vec temp
                    vector<double> temp;
                    for(int k = 0;k<cards.size(); ++k){
                        if(k!=i&&k!=j){
                            temp.push_back(cards[k]);
                        }
                    }
                    //-遍历运算符
                    for(int k = 0;k<operators.size();++k){
                        if(k<2&&i>j){
                            continue;
                        }
                        double otemp;
                        if(operators[k] == '+'){
                            otemp = cards[i]+cards[j];
                        }else if(operators[k] == '*'){
                            otemp = cards[i]*cards[j];
                        }else if(operators[k] == '-'){
                            otemp = cards[i]-cards[j];
                        }else{
                            if(fabs(cards[j])<epsilon){
                                continue;
                            }
                            otemp = cards[i]/cards[j];
                        }
                        temp.push_back(otemp);
                        if(judgeVec(temp)){
                            return true;
                        }
                        temp.pop_back();
                    }
                }
            }
        }
        //-如果所有操作符都不符合要求
        return false;
    }
};
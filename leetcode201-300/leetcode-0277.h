#include "utils.h"
// *搜寻名人，给定n个人0~n-1,提供api ：bool knows(int a, int b); 来确认A是否认识B
// *返回名人：被人知道而不知道别人的人。如果不存在名人返回-1
class Solution {
public:
    //-思路：我有个很有意思的想法，使用双端队列来存所有人
    //-每次取一头一尾，使用knows排除肯定不是名人的人，pop到最后只剩一个人的时候，最后判断一次该人和其它的人的关系得到结果
    int findCelebrity(int n) {
        deque<int>persons;
        for(int i = 0;i<n;++i){
            persons.push_back(i);
        }
        while(persons.size()>1){
            int person1 = persons.front();
            int person2 = persons.back();
            //-如果A认识B,B或者不认识A或者认识A,都可以把A排除
            if(knows(person1,person2)){
                persons.pop_front();
            }
            //-如果A不认识B。B或者认识或者不认识A，都可以把B排除
            else{
                persons.pop_back();
            }
        }
        //-判断最后一个人
        int lastperson = persons.front();
        bool sign = true;
        for(int i =0;i<n;++i){
            if(i == lastperson){
                continue;
            }
            if(!knows(i,lastperson)||knows(lastperson,i)){
                sign = false;
                break;
            }
        }
        return sign?lastperson:-1;
    }
};
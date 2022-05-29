#include "utils.h"
// *螺旋生成二维数组
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        //-生成二维数组
        vector<vector<int>>res(n,vector<int>(n,0));
        //-依旧螺旋填入元素即可
        int topbounds = 0;
        int downbounds = n;
        int leftbounds = 0;
        int rightbounds = n;
        //-填入元素
        int ele = 1;
        //-停止界限
        int target = n*n+1;
        //-临时坐标
        int i = 0;
        int j = 0;
        char direction = 'r';
        //-使用ele和target的关系来判断是否终止,这样能保证终止前一定不会越界
        while(ele<target){
            switch(direction){
                case 'r':
                    while(j<rightbounds){
                        res[i][j] = ele;
                        ++ele;
                        ++j;
                    }
                    ++topbounds;
                    --j;
                    ++i;
                    direction = 'd';
                    break;
                case 'd':
                    while(i<downbounds){
                        res[i][j] = ele;
                        ++ele;
                        ++i;
                    }
                    --rightbounds;
                    --i;
                    --j;
                    direction = 'l';
                    break;
                case 'l':
                    while(j>=leftbounds){
                        res[i][j] = ele;
                        ++ele;
                        --j;
                    }
                    --downbounds;
                    ++j;
                    --i;
                    direction = 'u';
                    break;
                case 'u':
                    while(i>=topbounds){
                        res[i][j] = ele;
                        ++ele;
                        --i;
                    }
                    ++leftbounds;
                    ++i;
                    ++j;
                    direction = 'r';
                    break;
            }
        }
        return res;
    }
};
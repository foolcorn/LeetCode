#include "utils.h"
// *字典序第k小数字
class Solution {
public:
    int getSteps(int curr, long n) {
        int steps = 0;
        long first = curr;
        long last = curr;
        while (first <= n) {
            steps += min(last, n) - first + 1;
            first = first * 10;
            last = last * 10 + 9;
        }
        return steps;
    }

    int findKthNumber(int n, int k) {
        int curr = 1;
        k--;
        while (k > 0) {
            int steps = getSteps(curr, n);
            if (steps <= k) {
                k -= steps;
                curr++;
            } else {
                curr = curr*10;
                k--;
            }
        }
        return curr;
    }
};

class Solution {
    public int findKthNumber(int n, int k) {
        int curr = 1;//-从1开始，1是字典序最小的
        k--;//-如果k=1，则不进入下面的循环，直接返回1，否则说明1不是目标，找第k-1个小的数
        while (k > 0) {
            int steps = count(curr, n);//-steps=当前节点curr下有多少比n小的子节点(包括n)
            if (steps <= k) {//-不够，需要去邻近节点找
                curr++;//-+1意味着到达了邻近兄弟节点
                k = k - steps;
                //-意味着前面的steps个数包含在在curr节点下，接下来进入兄弟节点找第k-steps小的数
            } else {//-否则，在curr下
                k--;//-减去当前节点
                curr = curr * 10;//-从最左侧开始搜寻
            }
        }
        return curr;
    }

    public static int count(int curr, int n) {//-计算节点curr下有多少比n小的子节点
        int steps = 0;
        long first = curr;
        long last = curr;
        while (first <= n) {//-当前层有符合要求的节点
            steps += Math.min(last, n) - first + 1;//-汇入
            first = first * 10;//-进入到下一层
            last = last * 10 + 9;//-进入到下一层
        }
        return steps;
    }
}
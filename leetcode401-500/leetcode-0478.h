#include "utils.h"
// *在圆内随机生成点
//-在更大的范围内生成随机数，并去掉不符合条件的随机数
class Solution {
private:
    mt19937 gen{random_device{}()};
    uniform_real_distribution<double>dis;//-均匀分布,头文件<random>
    double x_center;
    double y_center;
    double radius;
public:
    Solution(double radius, double x_center, double y_center):dis(-radius,radius),
    x_center(x_center), y_center(y_center),radius(radius){}

    vector<double> randPoint() {
        while(true){
            //-生成一个xy；
            double x = dis(gen);
            double y = dis(gen);
            if(x*x+y*y<radius*radius){
                return {x_center+x,y_center+y};
            }
        }
    }
};


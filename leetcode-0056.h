// *合并区间
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //-合并区间按起点升序排序,尾巴排不排序其实随意
        vector<vector<int>>temp =  intervals;
        vector<vector<int>>res;
        sort(temp.begin(), temp.end(),[](vector<int> a,vector<int> b){
            return a[0] < b[0];
        });
        //-临时起点和终点
        int start = temp[0][0];
        int end = temp[0][1];
        for(int i = 1; i < temp.size();++i){
            int temp_start = temp[i][0];
            int temp_end = temp[i][1];
            //-如果当前区间和之前区间不重叠了
            if(temp_start>end){
                //-先把上一个区间入res
                res.push_back({start,end});
                start = temp_start;
                end = temp_end;
                continue;
            }
            //-如果有重叠，判断尾巴要不要更新
            if(temp_end>end){
                end = temp_end;
            }
        }
        res.push_back({start,end});
        return res;
    }
};
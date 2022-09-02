//-比较版本号
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int length1 = version1.size();
        int length2 = version2.size();
        int p1 = 0;
        int p2 = 0;
        while(p1 < length1 || p2 < length2){
            int temp1 = 0;
            for(p1<length1 && version1[p1]!='.';++p1){
                temp1 = temp*10+(version1[p1]-'0');
            }
            ++p1;//-跳过.
            int temp2 = 0;
            for(p2<length2 && version2[p2]!='.';++p2){
                temp2 = temp*10+(version2[p2]-'0');
            }
            ++p2;
            if(temp1!=temp2){
                return temp1>temp2?1:-1;
            }
        }
        return 0;
    }
};
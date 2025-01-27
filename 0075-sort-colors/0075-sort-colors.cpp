class Solution {
public:
    void sortColors(vector<int>& nums) {
        int z=0,o=0,t=0;
        for(auto i:nums){
            if(i==0)z++;
            else if(i==1)o++;
            else t++;
        }
        for(auto &i:nums){
            if(z){
                i=0;
                z--;
            }
            else if(o){
                i=1;
                o--;
            }else{
                i=2;
                t--;
            }
        }
    }
};
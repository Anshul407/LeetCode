class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int mini=INT_MAX;
        int ind=-1;
        int j=0;
        for(auto i:arrays){
            if(mini>i[0]){
                mini=i[0];
                ind=j;
            }
            j++;
            
        }
        j=0;
        int maxi=INT_MIN;
        for(auto i:arrays){
           if(maxi<i[i.size()-1]&&j!=ind){
            maxi=i[i.size()-1];
           }
           j++;
        }
        return abs(maxi-mini);

    }
};
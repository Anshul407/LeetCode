class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;
        int ans=INT_MIN;
        while(i<height.size()&&j>=0){
            int sol=min(height[i],height[j])*(j-i);
            ans=max(sol,ans);
            if(height[i]>height[j]){
                j--;
            }
            else{
                i++;
            }
        }
        
        return ans;
    }
};
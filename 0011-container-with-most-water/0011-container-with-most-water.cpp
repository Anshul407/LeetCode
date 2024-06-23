class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0,j=height.size()-1;

        int ans=INT_MIN;
        while(i<height.size()&&j>=0){
            if(height[i]>height[j]){
                int sol=min(height[i],height[j])*(j-i);
                ans=max(sol,ans);
                j--;
            }
            else{
                int sol=min(height[i],height[j])*(j-i);
                ans=max(sol,ans);
                i++;
            }
        }
        
        return ans;
    }
};
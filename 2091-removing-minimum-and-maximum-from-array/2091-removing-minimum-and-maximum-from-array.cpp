class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini=INT_MAX,maxi=INT_MIN,ind=-1,ind2=-1;
        for(int i=0;i<nums.size();i++){
            mini=min(nums[i],mini);
            maxi=max(maxi,nums[i]);
        }
        for(int i=0;i<nums.size();i++){
           if(mini==nums[i])ind=i;
            if(maxi==nums[i])ind2=i;
        }
        mini=ind;
        maxi=ind2;

        cout<<maxi<<" "<<mini<<" ";

        int c1=max(mini,maxi)+1;
        int c2=mini+1+(nums.size()-maxi);
        int c3=maxi+1+(nums.size()-mini);
        int c4=max(nums.size()-maxi,nums.size()-mini);

        return min({c1,c2,c3,c4});
    }
};
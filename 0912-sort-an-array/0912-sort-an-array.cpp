class Solution {
public:
    vector<int>merge(vector<int>a,vector<int>b){
        if(a.size()==0&&b.size()!=0)return b;
        if(a.size()!=0&&b.size()==0)return a;
        if(a.size()==0&&b.size()==0)return {};

        int i=0,j=0;
        vector<int>ans;
        while(i<a.size()&&j<b.size()){
            if(a[i]>=b[j]){ans.push_back(b[j]);
            j++;}
            else {
                ans.push_back(a[i]);
                i++;
            }
        }
        while(i<a.size()){
            
                ans.push_back(a[i]);
                i++;
            
        }
         while(j<b.size()){
            
                ans.push_back(b[j]);
                j++;
            
        }

        return ans;
        
    }
    vector<int> solve(vector<int>& nums,int i,int j){
        if(i>j)return {};
        if(i==j)return {nums[i]};
        int mid=(i+j)/2;
        vector<int>left=solve(nums,i,mid);
        vector<int>right=solve(nums,mid+1,j);
        vector<int>ans=merge(left,right);
        return ans;

    }
    vector<int> sortArray(vector<int>& nums) {
       return  solve(nums,0,nums.size()-1);
    }
};
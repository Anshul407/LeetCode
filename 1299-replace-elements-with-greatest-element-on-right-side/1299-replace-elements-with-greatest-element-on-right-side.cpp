class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int curm=INT_MIN;
        vector<int>ans;
        for(int i=arr.size()-1;i>=0;i--){
            if(curm==INT_MIN)ans.push_back(-1);
            else ans.push_back(curm);
            if(arr[i]>curm)curm=arr[i];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
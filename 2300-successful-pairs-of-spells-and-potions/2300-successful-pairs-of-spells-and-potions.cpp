class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int>ans;
        for(auto n:spells){
            int i=0,j=potions.size()-1;
            while(i<=j){
                int mid=(i+j)/2;
                if(potions[mid]*n>=success)j=mid-1;
                else i=mid+1;
            }
            ans.push_back(potions.size()-i);
        }

        return ans;
    }
};
class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        stack<pair<int,int>>st;
        int cnt=0;
        vector<int>ans;
        for(int i=heights.size()-1;i>=0;i--){
            cnt=0;
            while(!st.empty()&&st.top().first<heights[i])cnt++,st.pop();
            if(!st.empty())cnt++;
            ans.push_back(cnt);
            st.push({heights[i],i});
        
        }reverse(ans.begin(),ans.end());
        return ans;
    }
};
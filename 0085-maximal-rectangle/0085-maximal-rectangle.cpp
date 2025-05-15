class Solution {
public:
    int solve(vector<int>&cur){
        stack<int>st;
        int ans=0;
        for(int i=0;i<=cur.size();i++){
            while(!st.empty()&&(i==cur.size()||cur[st.top()]>=cur[i])){
                auto height=cur[st.top()];
                st.pop();
                auto width=0;
                if(st.empty())width=i;
                else{
                    width=i-st.top()-1;
                }
                ans=max(ans,width*height);
            }st.push(i);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans=0;
        for(int i=0;i<matrix.size();i++){
        vector<int>cur;
        for(int j=0;j<matrix[0].size();j++){
            int k=i;
            int cnt=0;
            while(k>=0){
                if(matrix[k][j]=='0')break;
                cnt++;
                k--;
            }
            cur.push_back(cnt);
        }
        ans=max(ans,solve(cur));
        }return ans;
    }
};
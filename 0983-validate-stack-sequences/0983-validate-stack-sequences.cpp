class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int>st;
        st.push(pushed[0]);
        int i=1;
        int j=0;
        while(j<pushed.size()&&i<pushed.size()){
            while((st.empty()||st.top()!=popped[j])&&i<pushed.size()){
                st.push(pushed[i]);
                i++;
            }      
            if(st.top()!=popped[j])return 0;
            else st.pop(),j++;
        }
        while(j<pushed.size()&&st.top()==popped[j]){
            j++;
            st.pop();
        }return st.empty();
    }
};
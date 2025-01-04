class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int>st,prev,curr;
        for(int i=0;i<arr.size();i++){
            int cur=arr[i];
            st.insert(cur);
            for(int j=i+1;j<arr.size();j++){
                cur|=arr[j];
                st.insert(cur);
            }
        }
        return st.size();
    }
};
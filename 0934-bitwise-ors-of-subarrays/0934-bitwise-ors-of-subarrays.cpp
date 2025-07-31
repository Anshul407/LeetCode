class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int>st;
        unordered_set<int>prev;
        
        for(int i=0;i<arr.size();i++){
            unordered_set<int>cur;
            int curr=arr[i];
            cur.insert(curr);
            for(auto i:prev){
                cur.insert(curr|i);
            }
            prev=cur;
            cur.clear();

            for(auto c:prev){ 
                st.insert(c);
            }
        }
        return st.size();
    }
};
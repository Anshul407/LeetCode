class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        map<int,int>mp,mp2;
        vector<int>ans(A.size(),0);
        ans[0]=(A[0]==B[0]);
        mp[A[0]]++;
        mp2[B[0]]++;
      
        for(int i=1;i<A.size();i++){
            mp[A[i]]++;
            mp2[B[i]]++;
            if(A[i]==B[i])ans[i]=ans[i-1]+1;
            else { 
                ans[i]=ans[i-1]+mp[B[i]]+mp2[A[i]];
            }
        }
        return ans;
    }
};
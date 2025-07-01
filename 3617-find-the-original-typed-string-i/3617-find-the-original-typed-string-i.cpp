class Solution {
public:
    int possibleStringCount(string word) {
        int ans=1;
        int i=0;
        while(i<word.size()){
            int j=i+1;
            int cnt=0;
            while(j<word.size()&&word[j]==word[i]){j++;cnt++;}
            ans+=cnt;
            i=j;
        }
        return ans;
    }
};
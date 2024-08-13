class Solution {
public:
    int strStr(string haystack, string needle) {
        int m=needle.size();
        int n=haystack.size();
        if(n<m)return -1;
        // if(n==m)return 0;
        for(int i=0;i<=haystack.size()-m;i++){
            if(haystack.substr(i,m)==needle)return i;
        }
        return -1;
    }

};
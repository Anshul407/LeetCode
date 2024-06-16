class Solution {
public:
    int totalMoney(int n) {
        int ans=0;
        int flag=0;
        for(int i=0;i<n;i++){
            if(i%7==0)flag++;
            ans+=((i%7)+flag);
        }
        return ans;

    }
};
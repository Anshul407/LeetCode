class Solution {
public:
    int minimumNumbers(int num, int k) {
         if(num==0)return 0;
         if(k==0&&num%10!=0)return -1;
        if(num%2!=0&&k%2==0)return -1;

        if(num%10==k)return 1;

        if(num<k)return -1;
        
        int cnt=0;
        while(num>0&&num%10!=k){
            num-=k;
            cnt++;
        }
        if(num%10==k)
        return cnt+1;
        return -1;

    }
};
class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int ans=0;
        for(int i=low;i<=high;i++){
            auto cur=to_string(i);
            if(cur.size()%2==1)continue;
            int k=cur.size()/2;
            int j=k-1;
            int f=1;
            int a=0;
            int b=0;
            while(k<cur.size()&&j>=0){
                a+=(cur[k]-'0');
                b+=(cur[j]-'0');
                k++;
                j--;
            }
            if(a==b)cout<<cur<<" "<<a<<" "<<b<<"--";
            ans+=(a==b);

            
        }return ans;
    }
};
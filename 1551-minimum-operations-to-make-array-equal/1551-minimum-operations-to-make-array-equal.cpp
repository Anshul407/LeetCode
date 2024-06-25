class Solution {
public:
    int minOperations(int n) {
        vector<int>v;
        for(int i=0;i<n;i++){
            v.push_back((2 * i) + 1);
        }
        int mid=v.size()/2;
       
         for(auto i:v)cout<<i<<" ";   

        int pointer=v[mid];
        if(v.size()%2==0)pointer--;
        int ans=0;
        for(int i=v.size()-1;i>=mid;i--){
         
            ans+=(v[i]-pointer);
        }
        return ans;
    

    }
};
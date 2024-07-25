class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int>av;
        int j=0;
        for(auto i:capacity){
            
            av.push_back(i-rocks[j]);
            j++;
        }
        sort(av.begin(),av.end());
        int ans=0;
        for(auto i:av){
            if(i>0){
                if(i>additionalRocks){continue;
                }
                
                additionalRocks-=i;
                i-=i;
                
               

            }
            if(i==0)ans++;
        }
      
        // for(auto i:av){
        //     cout<<i<<" ";
        //     if(i==0)ans++;
        // }
        return ans;

    }
};
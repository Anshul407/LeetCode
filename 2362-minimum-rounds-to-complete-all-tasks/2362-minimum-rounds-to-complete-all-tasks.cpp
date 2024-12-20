class Solution {
public:
    //prioriy queue kyu use kia hai?
    //mereko ab pta chl gya ki utna jarrori nahi tha pehle 3 pairs ko remove krna
    //hata du tera kuch code??
    //tikh hain
    
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> mp;
        for(auto it:tasks)
        {
            mp[it]++;
        }
        // priority_queue<pair<int,int>> pq;
        // for (auto [n,c]:mp) {
        // pq.push({c,n});
        // }
    //    int count=0;
    //    // for(auto v:mp)
   //     // {   count++;
        //     auto [c,n]=pq.top();
        //     pq.pop();
        //     if(c%3==0||c%3==2)
        //     {
        //         c-=3;
        //     }
        //     else if(c%2==0)
        //     {
        //         c-=2;
        //     }
        //     else{
        //         return -1;
        //     }
        //     if(c!=0)
        //     {
        //         pq.push({c,n});
        //     }
        // }
        // return count;
        int ans=0;
        for(auto v:mp){
            auto nodeocc=v.second;
            if(nodeocc==1)return -1;
            if(nodeocc%3==0){   ///agr 3 se divisible hai to directly mai 3,3 ka piar le lunga so total op=occ/3
                ans+=nodeocc/3;
            }
            else{
               ans+=(nodeocc/3);
               ans++;
            }
            //ruk jaaa
            //hogya

        }
        return ans; //main kuch improvis e kru??ans;

    }
};
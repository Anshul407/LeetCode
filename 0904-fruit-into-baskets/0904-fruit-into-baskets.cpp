class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i=0,j=0;
        int bag=0;
       unordered_map<int,int>mp;
       int ans=0;
        while(i<fruits.size()&&j<fruits.size()){
           if(mp.find(fruits[j])==mp.end()&&bag<2){
                mp[fruits[j]]++;
                j++;
                bag++;
                

           }else if((mp.find(fruits[j])==mp.end())||(mp[fruits[j]]==0)&&bag>=2){
                  int currans=0;
                  for(auto i:mp){
                    currans+=i.second;
                  }
                  ans=max(ans,currans);
                  int data=fruits[j-1];
                  int target;
                  for(auto i:mp){
                    if(i.first==data)continue;
                    else if(i.second>0){
                        target=i.first;
                    }
                  }
                  while(mp[target]>0){
                    mp[fruits[i]]--;
                    i++;
                  }
                  mp.erase(target);
                  mp[fruits[j]]++;
                  j++;
           }else{
            mp[fruits[j]]++;
            j++;
           }
        }
        int currans=0;
                  for(auto i:mp){
                    cout<<i.first<<" "<<"s"<<i.second<<" ";
                    currans+=i.second;
                  }
        return max(ans,currans);
    }
};
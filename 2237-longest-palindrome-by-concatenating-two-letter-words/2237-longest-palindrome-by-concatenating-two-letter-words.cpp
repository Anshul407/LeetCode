class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int>mp;  
        for(auto i:words){
            mp[i]++;
        }
        int ans=0;
        for(auto i:words){
            auto cur=mp[i];
            if(cur==0)continue;
            string c=i;
            reverse(c.begin(),c.end());
            if(c==i){
                if(cur%2){
                    cur--;
                }
                ans+=(cur*c.size());
                mp[i]-=cur;
                cout<<mp[i]<<" ";
                if(mp[i]==0)mp.erase(i);
                continue;
            }
            cout<<c<<" ";
            auto cur2=mp[c];
            int mini=min(cur,cur2);
            ans+=(2*mini*i.size());
            mp[i]-=mini;
            if(mp[i]==0)mp.erase(i);
            mp[c]-=mini;
            if(mp[c]==0)mp.erase(c);
        }
        int cur=0;
        for(auto i:mp){
            cout<<i.second;
            if(i.second==0)continue;
            string c=i.first;
            reverse(c.begin(),c.end());
            if(c==i.first)
            cur=max(cur,(int)c.size());
        }
        ans+=cur;
        return ans;

        
    }
};
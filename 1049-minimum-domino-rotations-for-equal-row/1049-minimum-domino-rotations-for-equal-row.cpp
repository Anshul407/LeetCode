class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        unordered_map<int,int>mp,mp2;
        for(auto i:tops)mp[i]++;
        for(int i=0;i<bottoms.size();i++){
            if(bottoms[i]!=tops[i])mp2[bottoms[i]]++;
        }
        int ans=INT_MAX;
        for(int i=1;i<=6;i++){
            cout<<mp[i]<<" ";
            if(mp[i]+mp2[i]==tops.size())ans=min(ans,mp2[i]);
        }
        unordered_map<int,int>mp3,mp4;
        for(auto i:bottoms)mp3[i]++;
        for(int i=0;i<tops.size();i++){
            if(bottoms[i]!=tops[i])mp4[tops[i]]++;
        }
        
        for(int i=1;i<=6;i++){
            cout<<mp[i]<<" ";
            if(mp3[i]+mp4[i]==tops.size())ans=min(ans,mp4[i]);
        }
        return ans==INT_MAX?-1:ans;
    }
};
class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        int i=0,j=skill.size()-1;
        int p=skill[0];
        p+=skill.back();
        long long ans=0;
        while(i<j){
            if(skill[i]+skill[j]!=p)return -1;
            else ans+=(long long)(skill[i]*skill[j]);
            i++;
            j--;
        }
        return ans;
    }
};
class Solution {
public:
    bool check(int k,vector<int>&t,vector<int>&w,int p,int s){
        vector<int>v;
        multiset<int>st;
        for(int i=0;i<min(k,(int)t.size());i++){
            v.push_back(t[i]);
            st.insert(w[i]);
        }
        reverse(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            auto cur=v[i];
            auto it=prev(st.end());
            if(*it>=cur){
                st.erase(it);
            }else if(p<=0)return 0;
            else{
                auto x=st.lower_bound(cur-s);
                if(x==st.end())return 0;
                st.erase(x);
                p--;

            }
            
        }return 1;
    }
    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(),tasks.end());
        sort(workers.rbegin(),workers.rend());
        int i=0,j=min((int)workers.size(),(int)tasks.size());
        int ans=0;
        while(i<=j){
            auto mid=(i+j)/2;
            if(check(mid,tasks,workers,pills,strength)){
                ans=mid;
                i=mid+1;
            }else j=mid-1;
        }return ans;
    }
};
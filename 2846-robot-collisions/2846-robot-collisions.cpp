class Solution {
public:
    static bool cmp(pair<int,int>&p,pair<int,int>&q){
        return p.second<q.second;
    }
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<vector<int>>comb;
        for(int i=0;i<positions.size();i++){
            int p=1;
            if(directions[i]=='R')p=0;  
            comb.push_back({positions[i],healths[i],p,i});
        }vector<pair<int,int>>ans;
        sort(comb.begin(),comb.end());
        stack<pair<int,int>>st;
        for(auto i:comb){
            auto cur=i[0];
            
            auto h=i[1];
            auto d=i[2];
            auto c=i[3];
            if(d==0)st.push({h,c});
            else {
                if(st.empty())ans.push_back({h,c});
                else{
                    auto curele=st.top();
                    st.pop();
                    if(curele.first==h)continue;
                    if(curele.first>h)st.push({curele.first-1,curele.second});
                    else {
                        h--;
                        while(!st.empty()&&st.top().first<h){
                            st.pop();
                            h--;
                        }
                        if(st.empty()){
                            ans.push_back({h,c});
                        }else {
                            if(st.top().first==h)st.pop();
                            else {
                                auto xx=st.top();
                                
                                st.pop();
                                st.push({xx.first-1,xx.second});
                            }
                        }
                    }
                }
            }
        }
        while(!st.empty()){
            ans.push_back({st.top().first,st.top().second});
            st.pop();
        }
        sort(ans.begin(),ans.end(),cmp);
        vector<int>finans;
        for(auto i:ans)finans.push_back(i.first);

        return finans;
    }
};
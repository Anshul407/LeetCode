class Solution { 
public:     
    int f(vector<int>& c, int x,long &ans) {     
         ans=LONG_MAX;    
        int i = 0,j=c.size()-1;         
        while (i <=j) {             
            int mid = i + (j - i) / 2;             
            if (c[mid] < x) {                 
                i = mid + 1;             
            } else {    
                ans=c[mid];         
                j = mid-1; 
            }                            
        }  
              
        return ans!=LONG_MAX;     
    }     
    vector<int> findRightInterval(vector<vector<int>>& intervals) {         
        vector<int> x;         
        map<int, int> mp;         
        for (int i = 0; i < intervals.size(); i++) {             
            x.push_back(intervals[i][0]);             
            mp[intervals[i][0]] = i;         
        }         
        sort(x.begin(), x.end());         
        vector<int> ans;         
        for (auto i:intervals) {  
            long c;           
            if(f(x, i[1],c))             
            ans.push_back(mp[(int)c]);     
            else ans.push_back(-1);    
        }         
        return ans;      
    } 
};

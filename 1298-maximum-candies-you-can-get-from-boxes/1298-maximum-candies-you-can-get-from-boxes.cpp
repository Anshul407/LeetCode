class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        queue<int> q;
        vector<int> vis(status.size(), 0); 
        for(int i = 0; i < initialBoxes.size(); i++) {
            if(status[initialBoxes[i]] == 1) {
                q.push(initialBoxes[i]);  // Push open boxes to the queue
            } else {
                vis[initialBoxes[i]] = 1;  // Mark locked boxes
            }
        }

        int ans = 0;  
        while(!q.empty()) {
            int it = q.front();
            q.pop();

           
            ans += candies[it];
            candies[it] = 0;  // Avoid double counting

            // Process all contained boxes in the current box
            for(auto v : containedBoxes[it]) {
                if(status[v] == 1 && candies[v] > 0) {
                    q.push(v);  // If the box is open and has candies, push it into the queue
                } else {
                    vis[v] = 1;  // Otherwise, mark it as locked and visited
                }
            }

            // Process all keys found in the current box
            for(auto ke : keys[it]) {
                status[ke] = 1;  // Unlock the box with the key
                if(vis[ke] == 1 && candies[ke] > 0) {
                    q.push(ke);  // If the box was locked but visited, now unlock it and push it into the queue
                }
            }
        }

        return ans;
    }
};

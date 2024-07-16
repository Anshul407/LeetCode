class Solution {
public:
    void dfs(vector<vector<int>>&img,int sr,int sc,int col,int m){
        img[sr][sc]=col;
        if(sr!=0){
            int up=sr-1;
            if(img[up][sc]==m)
            dfs(img,up,sc,col,m);
        }
        if(sc!=0){
            int up=sc-1;
            if(img[sr][up]==m)
            dfs(img,sr,up,col,m);
        }
        if(sr<img.size()-1){
            int up=sr+1;
            if(img[up][sc]==m)
            dfs(img,up,sc,col,m);
        }
        if(sc<img[0].size()-1){
            int up=sc+1;
             if(img[sr][up]==m)
            dfs(img,sr,up,col,m);
        }

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image[sr][sc];
        if(color==m)return image;
        dfs(image,sr,sc,color,m);
        return image;
    }
};
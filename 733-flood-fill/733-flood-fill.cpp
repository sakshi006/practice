class Solution {
public:
    
    void dfs(int sr,int sc, int n, int m , int color, vector<vector<int>>& image, int initialColor)
    {
        if(sr<0 || sr>=n || sc<0 ||sc>=m || image[sr][sc] != initialColor ||image[sr][sc] == color)
            return;
        
        image[sr][sc] = color;
        
        dfs(sr+1,sc,n,m,color,image, initialColor);
        dfs(sr,sc+1,n,m,color,image, initialColor);
        dfs(sr-1,sc,n,m,color,image, initialColor);
        dfs(sr,sc-1,n,m,color,image, initialColor);
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        int n = image.size();
        int m = image[0].size();
        
        int initialColor = image[sr][sc];
        dfs(sr,sc,n,m,color, image,initialColor );
        
        return image;
    }
};
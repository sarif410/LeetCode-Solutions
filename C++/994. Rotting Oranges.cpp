class Solution {
public:
    bool safe(int x, int y, int n, int m){
        if(x>=0 && x<n && y>=0 && y<m) return true;
        else return false;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        queue<pair<int,int>> q;
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push(make_pair(i,j));
                    visited[i][j]=true;
                }
            }
        }
        int dx[4]={0,0,1,-1};
        int dy[4]={1,-1,0,0};
        while(!q.empty()){
            int k=q.size();
            bool ok=false;
            while(k--){
                pair<int,int> p=q.front();
                q.pop();
                int a=p.first;
                int b=p.second;
                for(int i=0;i<4;i++){
                    int x=a+dx[i];
                    int y=b+dy[i];
                    if(safe(x,y,n,m) && grid[x][y]==1 && visited[x][y]==false){
                        ok=true;
                        grid[x][y]=2;
                        visited[x][y]=true;
                        q.push(make_pair(x,y));
                    }
                }
            }
            if(ok) ans++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) return -1;
            }
        }
        return ans;
    }
    
};

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        map<vector<int>, int> mp;
        while(N>0){
            vector<int> temp(8,0);
            mp[cells]=N--;
            for(int i=1;i<7;i++){
                if(cells[i-1]==cells[i+1]) temp[i]=1;
                else temp[i]=0;
            }
            cells=temp;
            if(mp.find(cells)!=mp.end()){
                N%=mp[cells]-N;
            }
        }
        return cells;
    }
};

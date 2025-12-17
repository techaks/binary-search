class Solution {
public:
    int solve(vector<vector<int>>& items, int query) {
        int l =0;
        int r = items.size()-1;
        int beauty = 0;
        while(l<=r){
            int mid = l+(r-l)/2;
            if(items[mid][0]>query){
                r=mid-1;
            }else{
                beauty=max(beauty , items[mid][1]);
                l=mid+1;
            }

        }
        return beauty;

    }
    vector<int> maximumBeauty(vector<vector<int>>& items,
                              vector<int>& queries) {
        int n = items.size();
        int m = queries.size();
        sort(begin(items), end(items)); // ex-[[1,2],[2,4],[3,2],[3,5]];
        int maxBeauty = items[0][1];
        for (int i = 1; i < n; i++) {
            maxBeauty = max(maxBeauty, items[i][1]);
            items[i][1] = maxBeauty;
        }

        vector<int> res(m);
        for (int i = 0; i < m; i++) {
            int query = queries[i];
            res[i] = solve(items, query);
        }

        return res;
    }
};
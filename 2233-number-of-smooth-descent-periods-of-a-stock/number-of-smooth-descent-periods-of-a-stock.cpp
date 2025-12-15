class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long res =0;

        int count=1;
        for(int i=0 ; i< prices.size();i++){
            if( i>0 && prices[i] + 1 ==prices[i-1]){
                count++;
            }else count =1;

            res+=count;

        }

        return res;
        
    }
};
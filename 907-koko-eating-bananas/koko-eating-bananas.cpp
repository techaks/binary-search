class Solution {
public:
    bool eat(vector<int>& piles, int mid , int h){
        int actual =0;
        for(int pile : piles){
            actual+=pile/mid;
            if(pile%mid!=0)actual++;
        }
        return actual<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n= piles.size();
        int l=1;
        int r= *max_element(begin(piles),end(piles));
        while(l<r){
            int mid = l+(r-l)/2;

            if(eat(piles,mid,h)){
                r=mid;
            }else{
                l=mid+1;
            }
        }

        return l;

        
    }
};
// revised version
using u128 = unsigned __int128;
class Solution {
public:
    static u128 check1(vector<int>& vect, int sz){
        u128 ans=0;
        for(int i=0; i<sz; i++)
            if (vect[i]==1) ans|=((u128)1<<i);
        return ans;
    }

    static int ctz(u128 x){
        uint64_t hi=x>>64, lo=x & ULLONG_MAX;
        if (x==0) return -1;
        if (lo!=0) return __builtin_ctzll(lo);
        return 64+__builtin_ctzll(hi);
    }

    static int numSpecial(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size(), ans=0;
        u128 col=0;//already check or not

        for(int i=0; i<m; i++){
            u128 mask=check1(mat[i], n);

            bool single=mask && !(mask & (mask-1));
            int j=ctz(mask);

            if (single&&!((col>>j) & 1)){
                col|=((u128)1<<j);

                int cnt=0;
                for(int k=0; k<m; k++)
                    cnt+=mat[k][j];
                ans+=cnt==1;
            }
            else
                col|=mask;
        }
        return ans;
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
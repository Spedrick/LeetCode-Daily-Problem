class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        set<int> st;
        while(n) st.insert(--n);

        for(auto edge: edges) {
            if(st.find(edge[1]) != st.end()) st.erase(edge[1]);
        }

        if (st.size() > 1) return -1;
        return *next(st.begin(),0);
        
    }
};
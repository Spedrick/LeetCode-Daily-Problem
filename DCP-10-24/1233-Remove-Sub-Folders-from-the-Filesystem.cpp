class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> res;
        sort(folder.begin(), folder.end());
        for(auto x: folder) {
            if(res.empty()) res.push_back(x);
            else {
                auto top = res.back();

                int i=0;
                while(i < top.size() && top[i] == x[i]) i++;

                if(i==top.size() && x[i] == '/') continue;
                else res.push_back(x);
            }
        }
        return res;        
    }
};
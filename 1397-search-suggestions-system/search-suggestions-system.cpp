class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());  // Step 1: sort
        
        vector<vector<string>> result;
        string prefix = "";
        int n = products.size();
        
        for (char c : searchWord) {
            prefix += c;
            vector<string> suggestions;
            
            // Step 2: binary search for prefix
            auto it = lower_bound(products.begin(), products.end(), prefix);
            
            // Step 3: collect up to 3 matching products
            for (int i = 0; i < 3 && it + i != products.end(); i++) {
                if ((it + i)->find(prefix) == 0) {
                    suggestions.push_back(*(it + i));
                } else {
                    break;
                }
            }
            
            result.push_back(suggestions);
        }
        
        return result;
    }
};

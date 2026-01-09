#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> freq;
        
        // Count occurrences
        for (int num : arr) {
            freq[num]++;
        }

        unordered_set<int> seen;
        for (auto& [num, count] : freq) {
            if (seen.count(count)) {
                return false; // Duplicate count found
            }
            seen.insert(count);
        }

        return true;
    }
};

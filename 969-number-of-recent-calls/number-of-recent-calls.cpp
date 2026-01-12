#include <queue>
using namespace std;

class RecentCounter {
private:
    queue<int> q;

public:
    RecentCounter() {
        // Queue initialized empty
    }
    
    int ping(int t) {
        q.push(t);
        
        // Remove requests older than t - 3000
        while (!q.empty() && q.front() < t - 3000) {
            q.pop();
        }
        
        return q.size();
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int size = nums.size();
        if (size == 0 || k == 0)    return {};
        vector<int> res(k, 0);
        priority_queue<pair<int, int>, 
                    vector<pair<int, int>>, 
                    greater<pair<int, int>>> pq;
        unordered_map<int, int> counter;
        for (int i = 0; i < size; i++)  
            counter[nums[i]]++;
        for (auto c : counter) {
            auto tmp = make_pair(c.second, c.first);
            if (pq.size() == k) {
                if (tmp < pq.top())
                    continue;
                pq.pop();
            }
            pq.push(tmp);
        }   
        while (!pq.empty()) {
            res[--k] = pq.top().second;
            pq.pop();
        }  
        return res;
    }
}; 

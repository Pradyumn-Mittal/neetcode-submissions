class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;

        for (int R = 0; R < nums.size(); R++) {

            // Remove indices that are outside the window
            while (!dq.empty() && dq.front() <= R - k) {
                dq.pop_front();
            }

            // Remove elements smaller than nums[R]
            // They can never become the maximum again
            while (!dq.empty() && nums[dq.back()] <= nums[R]) {
                dq.pop_back();
            }

            dq.push_back(R);

            // Window is valid
            if (R >= k - 1) {
                res.push_back(nums[dq.front()]);
            }
        }

        return res;
    }
};
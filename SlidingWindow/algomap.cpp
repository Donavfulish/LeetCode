//1004
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, maxLength = 0, zeroCount = 0;

        for (int right = 0; right < nums.size(); ++right) {
            if (nums[right] == 0) {
                zeroCount++;
            }
            while (zeroCount > k) {
                if (nums[left] == 0) {
                    zeroCount--;
                }
                left++;
            }
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};

//3
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastIndex;
        int left = 0, maxLength = 0;

        for (int right = 0; right < s.size(); right++) {
            if (lastIndex.find(s[right]) != lastIndex.end() && lastIndex[s[right]] >= left) {
                // Nếu gặp ký tự trùng trong cửa sổ hiện tại, dời left lên sau vị trí trùng
                left = lastIndex[s[right]] + 1;
            }
            lastIndex[s[right]] = right; // cập nhật vị trí mới nhất của ký tự
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};

//424
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int left = 0, maxLength = 0, maxFreq = 0;
        for (int right = 0; right <= s.size() - 1; right++) {
            freq[s[right] - 'A']++;
            maxFreq = max(maxFreq, freq[s[right] - 'A']);

            while (right - left + 1 - maxFreq > k) {
                freq[s[left] - 'A']--;
                left++;
            }

            maxLength = max(maxLength, right - left + 1);
        }
        return maxLength;
    }
};

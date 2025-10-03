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

//209
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int minLength = nums.size() + 1, sum = 0, left = 0;
        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];

            while (sum >= target) {
                minLength = min(minLength, right - left + 1);
                sum -= nums[left];
                left++;
            }
        }
        return ((minLength == nums.size() + 1) ? 0 : minLength);
    }
};

// subarray -> sliding window
// window have:
//      - Length: right - left + 1
//      - Condition: sum >= target -> use var sum to save sum of current
//      subarray, when >= k
//          move left until < k

// 567
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s2.size() < s1.size())
            return false;

        unordered_map<char, int> freq1;
        unordered_map<char, int> freq2;
        for (int i = 0; i < s1.size(); i++) {
            freq1[s1[i]]++;
            freq2[s2[i]]++;
        }

        if (freq1 == freq2)
            return true;

        int left = 0;
        for (int right = s1.size(); right < s2.size(); right++) {
            freq2[s2[right]]++;
            freq2[s2[left]]--;

            if (freq2[s2[left]] == 0)
                freq2.erase(s2[left]);

            left++;

            if (freq2 == freq1)
                return true;
        }
        return false;
    }
};

// permutation -> subarray contain full charachter of s1 -> sliding window
// Window have:
//      - Size: = s1 -> right - left + 1 = s1.size()
//      - Contain exactly char of s1 -> count freq of each char in s1, save
//      on map
//      - For in s2, change freq2, if length = s1 return true, if not ->
//      check if char not exist -> left++, continue. If exist -> increase
//      freq2, while freq2 > freq1 -> --freq2 and
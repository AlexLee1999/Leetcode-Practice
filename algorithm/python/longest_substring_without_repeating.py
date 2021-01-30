class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        count = 0
        max_count = 0
        tmp = []
        for i in range(len(s)):
            if s[i] in tmp:
                count = count - tmp.index(s[i]) 
                tmp = tmp[(tmp.index(s[i])+1):]
                tmp.append(s[i])
            else:
                count += 1
                if max_count < count:
                    max_count = count
                tmp.append(s[i])
        return max_count
                
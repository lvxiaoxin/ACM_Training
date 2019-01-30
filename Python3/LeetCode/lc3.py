# Brute Force

class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """

        if len(s) == 1:
            ans = 1
            return ans

        map_records = dict()

        for i in range(len(s) - 1):
            cur = s[i]
            sub_s = s[i+1:]
            count = 1
            temp_set = set()
            for k in range(len(s) - i - 1):
                if sub_s[k] != cur and sub_s[k] not in temp_set:
                    count += 1
                    temp_set.add(sub_s[k])
                else:
                    break
            # print(cur, count, map_records)
            if cur not in map_records:
                map_records[cur] = count
            if map_records[cur] < count:
                map_records[cur] = count
                
        ans = 0

        rc = list(map_records.values())

        for item in rc:
            if item > ans:
                ans = item
            else:
                continue

        return ans


if __name__ == "__main__":
    s = Solution()
    s.lengthOfLongestSubstring("abcdefghif")
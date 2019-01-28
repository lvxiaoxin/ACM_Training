class Solution:
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """

        ans = 0

        store_with_index = ""

        for cur in s:
            if cur not in store_with_index:
                store_with_index += cur
                ans = max(ans, len(store_with_index))
            else:
                cut = store_with_index.index(cur)
                store_with_index = store_with_index[cut + 1:] + cur

        return ans


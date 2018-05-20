class Solution:
    def selfDividingNumbers(self, left, right):
        """
        :type left: int
        :type right: int
        :rtype: List[int]
        """

        ans = []
        for i in range(left, right+1):
            now = i
            flag = 0
            while i != 0:
                num = i % 10
                if num == 0:
                    flag = 1
                    break
                if now % num == 0:
                    i //= 10
                    continue
                else:
                    flag = 1
                    break
            if flag == 1:
                continue
            else:
                ans.append(now)
        return ans
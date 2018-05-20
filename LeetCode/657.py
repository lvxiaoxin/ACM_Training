# class Solution:
#     def judgeCircle(self, moves):
#         """
#         :type moves: str
#         :rtype: bool
#         """
#         up, down, left, right = (0, 0, 0, 0)
#         str = ['U', 'D', 'L', 'R']
#         for i in range(len(moves)):
#             if moves[i] == str[0]:
#                 up += 1
#             if moves[i] == str[1]:
#                 down += 1
#             if moves[i] == str[2]:
#                 left += 1
#             if moves[i] == str[3]:
#                 right += 1
#         x = left - right
#         y = up - down

#         if x == 0 and y == 0:
#             return True
#         else:
#             return False
        


class Solution:
    def judgeCircle(self, moves):
        """
        :type moves: str
        :rtype: bool
        """
        return (moves.count('U') == moves.count('D')) and (moves.count('L') == moves.count('R'))
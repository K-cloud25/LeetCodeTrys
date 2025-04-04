class Solution(object):
    def removeOuterParentheses(self, s):
        """
        :type s: str
        :rtype: str
        """
        ret = ""
        count = 0
        for c in s:
            if (c == '(' and count > 0):
                ret += c
            if (c == '('):
                count += 1
            if (c == ')' and count > 1):
                ret += c
            if (c == ')'):
                count -= 1
        return ret
        
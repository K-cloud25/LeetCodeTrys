class Solution:
    def reverseWords(self, s: str) -> str:
        s = s.split(" ")
        s = s[::-1]
        s = [ x for x in s if len(x) > 0 ]
        return " ".join(s)
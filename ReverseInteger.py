class Solution:
    def reverse(self, x: int) -> int:
        x = str(x)[::-1]
        if(x[-1]=='-'):
            x = "-"+x[:-1]
        if(int(x) > 2147483647 or int(x) < -2147483648):
            return 0
        return int(x)

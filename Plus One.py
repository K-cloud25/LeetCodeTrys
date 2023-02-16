class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        temp = int("".join(map(str,digits)))
        return [int(x) for x in str(temp+1)]

class NumMatrix:

    def __init__(self, matrix: List[List[int]]):
        if not matrix or not matrix[0]:
            self.prefixSum = [[]]
            return
        m, n = len(matrix), len(matrix[0])
        self.prefixSum = [[0] * (n + 1) for _ in range(m + 1)]

        for i in range(m):
            for j in range(n):
                self.prefixSum[i+1][j+1] = (self.prefixSum[i][j+1] 
                                           + self.prefixSum[i+1][j] 
                                           - self.prefixSum[i][j] 
                                           + matrix[i][j])

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        return (self.prefixSum[row2+1][col2+1] 
                - self.prefixSum[row2+1][col1] 
                - self.prefixSum[row1][col2+1] 
                + self.prefixSum[row1][col1])
        


# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)
class Solution:
    def matrixReshape(self, mat: List[List[int]], r: int, c: int) -> List[List[int]]:
        
        # Checking Legal Condition for reshaping
        if(len(mat)*len(mat[0]) != r*c):
            return mat
        
        # flattening the n-D matrix to 1-D array
        mat = [item for sublist in mat for item in sublist]
        retmat = []
        for i in range(0,r):
            #forming r*c matrix by slicing and forming arrays
            retmat = ([mat[i:i+c] for i in range(0,len(mat),c)])
        return retmat

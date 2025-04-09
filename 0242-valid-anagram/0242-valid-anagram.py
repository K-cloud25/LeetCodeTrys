class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
    
        d = {}
        k = {}

        for i in range(len(s)):
            if ( d.get(s[i]) != None ):
                d[s[i]] += 1
            else:
                d[s[i]] = 1

            if ( k.get(t[i]) != None ):
                k[t[i]] += 1
            else:
                k[t[i]] = 1
        
        return k == d

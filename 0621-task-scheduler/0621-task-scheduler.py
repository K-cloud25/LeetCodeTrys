class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        l={}
        maxFreq=0
        countFreq=0
        sz=len(tasks)
        for i in tasks:
            l[i]=l.get(i,0)+1
        maxFreq=max(l.values())
        countFreq=sum( 1 for v in l.values() if v==maxFreq)
        return max(sz, (maxFreq-1)*(n+1)+countFreq)
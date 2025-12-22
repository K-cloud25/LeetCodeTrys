class Solution:
    def reorganizeString(self, s: str) -> str:
        mapp={}
        for c in s:
            mapp[c] = mapp.get(c,0)+1
        heap = [(-frq, char) for char, frq in mapp.items()]
        heapq.heapify(heap)
        res=[]
        pFreq = 0
        pChar = ""
        while heap:
            Frq,c = heapq.heappop(heap)
            res.append(c)

            if pFreq<0:
                heapq.heappush(heap, (pFreq, pChar))
            
            Frq+=1
            pFreq=Frq
            pChar=c

        if len(res) != len(s):
            return ""
        return "".join(res)
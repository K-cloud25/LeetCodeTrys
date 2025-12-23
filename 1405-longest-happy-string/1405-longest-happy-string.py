class Solution:
    def longestDiverseString(self, a: int, b: int, c: int) -> str:
        h = []
        if a:
            heappush(h, (-a, "a"))
        if b:
            heappush(h, (-b, "b"))
        if c:
            heappush(h, (-c, "c"))
        ans = ""
        st = []
        pre = ""
        count = 0
        while h:
            c, ch = heappop(h)
            c = -c
            if ch != pre or (count < 2):
                ans += ch
                c -= 1
                if c > 0: heappush(h, (-c, ch))
                if ch == pre: count += 1
                else:
                    pre = ch
                    count = 1
            elif h:
                c2, ch2 = heappop(h)
                c2 = -c2
                ans += ch2
                c2 -= 1
                if c > 0: heappush(h, (-c, ch))
                if c2 > 0: heappush(h, (-c2, ch2))
                count = 1
                pre = ch2
            else: break
        return ans
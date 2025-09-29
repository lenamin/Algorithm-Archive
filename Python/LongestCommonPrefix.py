class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        cs = ""

        if len(strs) == 1:
            return strs[0]

        srted = sorted(strs)

        first = srted[0]
        end = srted[len(strs) - 1]

        for f, e in zip(first, end):
            print(f, e)
            if f == e:
                cs += f
            else: return cs
        
        return cs
        
class Solution:

    def encode(self, strs: List[str]) -> str:
        """
            encode -> num#str 
            decode -> \\d#str-till-\\d
                   -> validation num#str => num == len(str)
        """
        encoded = [f"{len(s)}#{s}" for s in strs]
        # print("".join(encoded))
        return "".join(encoded)

    def decode(self, s: str) -> List[str]:
        """
        Find first # from 0 or start of new string
        say # is at j
        num#str
        num => start/0 to j-1
        j+1 + num => str
        """
        ans = []
        i = 0
        while i < len(s):
            j = s.find("#", i)
            # print(i, j)
            if j == -1:
                break
            num = int(s[i:j])
            # print(i, j, s[i:j], num)
            start = j+1
            end = start + num
            ans.append(s[start:end])
            i = end
            # print(start, end, i)
        return ans

                    
            


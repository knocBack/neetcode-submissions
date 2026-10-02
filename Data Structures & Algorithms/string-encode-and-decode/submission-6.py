class Solution:

    def encode(self, strs: List[str]) -> str:
        """
            encode -> num#str 
            decode -> \\d#str-till-\\d
                   -> validation num#str => num == len(str)
        """
        encoded = [f"{len(s)}#{s}" for s in strs]
        return "".join(encoded)

    def decode(self, s: str) -> List[str]:
        ans = []
        n = ""
        length = -1
        i = 0
        while i < len(s):
            if s[i].isdigit():
                n+=s[i]
            else:
                if s[i]=="#":
                    length = int(n)
                else:
                    length = -1
                n = ""
            if s[i]=="#" and length != -1:
                v = ""
                for j in range(length):
                    v+=s[i+j+1]
                print(v)
                ans.append(v)
                i+=length+1
            else:
                i+=1
        return ans

                    
            


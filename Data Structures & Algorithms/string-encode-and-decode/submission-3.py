class Solution:
    delimtter = ','
    escape_chr = "\\"

    def encode(self, strs: List[str]) -> str:
        encoded = f"{len(strs)}#"
        for s in strs:
            print(f"before: {s}")
            s = s.replace(',', '\\,')
            print(f"after: {s}")
            encoded+=s+','
        if len(strs) > 0:
            encoded = encoded[:-1]
        # encoded = ','.join(strs)
        print(f"encoded: {encoded}")
        print(f"len(encoded): {len(encoded)}")
        return encoded

    def decode(self, s: str) -> List[str]:
        match = re.search(r'(\d+)#', s)
        val = match.group(1)
        count = int(val)
        print(f"count1: {count}")
        s = s[len(val)+1:]
        if count == 0:
            return []
        strs = [ part.replace('\\,', ',') for part in re.split(r'(?<!\\),', s)]
        strs2 = [part.replace(r'\,', ',') for part in re.split(r'(?<!\\),', s)]
        for part in re.split(r'(?<!\\),', s):
            print(part)
        print(f"decoded: {strs}")
        print(f"decoded2: {strs2}")
        return strs
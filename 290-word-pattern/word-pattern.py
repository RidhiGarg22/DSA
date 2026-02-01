class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        words = s.strip().split()
        if len(pattern) != len(words):
            return False

        hm = {}
        used = set()

        for ch, word in zip(pattern, words):
            if ch in hm:
                if hm[ch] != word:
                    return False
            else:
                if word in used:
                    return False
                hm[ch] = word
                used.add(word)
        return True
        
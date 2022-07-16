class Solution:
    # @param A: list of integers
    # @return an integer
    def bulbs(self, A):
        cost = 0

        for b in A: #O(N)
            if cost % 2 == 0: b = b
            else: b = not b 

            if b % 2 == 1: continue
            else: cost += 1
            
        return cost




# n = 100
# answer = []
# for i in range(n):
#     if i % 15 == 0:
#         answer.append("FizzBuzz")
#     elif i % 3 == 0:
#         answer.append("Fizz")
#     elif i % 5 == 0:
#         answer.append("Buzz")
#     else:
#         answer.append(i)
    
# print(answer)


# 
class Solution:
    def fizzBuzz(self, n):
        answer = []
        for i in range(1, n + 1):
            s = ""
            if i % 3 == 0:
                s += "Fizz"
            if i % 5 == 0:
                s += "Buzz"
            answer.append(s or str(i))
        return answer

s = Solution()
print(s.fizzBuzz(60))
"""

TIME AND SPACE COMPLEXITY = O(n)

"""


"""
Importance of a set:
    1.Stores unique values only
    2. Automatically removes duplicates
    3. Uses hashing, just like dictionaries
"""

# class Solution(object):
#     def containsDuplicate(self, nums):
#         map = {}                     # Dictionary to store seen numbers
#         for i, v in enumerate(nums): # Loop through nums with index and value
#             if nums[i] in map:       # Check if current number already exists
#                 return True          # Duplicate found
#             map[v] = i               # Store number with its index
#         return False                 # No duplicates found


# class Solution(object):
#     def containsDuplicate(self, nums):
#         a = set(nums)               # Convert list to a set (removes duplicates)
#         if len(a) == len(nums):     # Compare lengths
#             return False            # No duplicates
#         else:
#             return True             # Duplicates exist



# BEST APPROACH - MORE CLEANER VERSION

class Solution(object):
    def containsDuplicate(self, nums):
        return len(set(nums)) != len(nums)
    





   

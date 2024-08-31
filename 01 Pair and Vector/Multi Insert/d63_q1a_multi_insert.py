n, value, position, count = [int(e) for e in input().split()]
nums = [int(e) for e in input().split()]
print("After call multiple_add")
nums = nums[:position] + [value]*count + nums[position:]
print("Size =", len(nums))
nums = [str(item) for item in nums]
print(" ".join(nums))
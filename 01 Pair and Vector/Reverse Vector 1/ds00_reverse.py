n = int(input())
nums = [int(e) for e in input().split()]
a,b = [int(e) for e in input().split()]
new_nums = nums[:a] + nums[a : b+1][::-1] + nums[b+1:]
new_nums = [str(item) for item in new_nums]
print(" ".join(new_nums))
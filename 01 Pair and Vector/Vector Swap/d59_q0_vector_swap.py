n1 = int(input())
nums1 = [int(e) for e in input().split()]
n2 = int(input())
nums2 = [int(e) for e in input().split()]
start1, end1 = [int(e) for e in input().split()]
start2, end2 = [int(e) for e in input().split()]
new1 = nums1[:start1] + nums2[start2:end2] + nums1[end1:]
new1 = [str(item) for item in new1]
new2 = nums2[:start2] + nums1[start1:end1] + nums2[end2:]
new2 = [str(item) for item in new2]
print("v1 has", len(new1))
print(" ".join(new1))
print("v2 has", len(new2))
print(" ".join(new2))
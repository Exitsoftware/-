n = int(input());
li = list(map(int,input().split()));


li.sort()
for i in li:
	print(i, end=" ")
print()
print()

# for i in range(len(li)):
# 	li1 = li[0:i+1]
# 	li2 = li[i:]

# 	sum1 = sum(li1)
# 	sum2 = sum(li2)

# 	result1 = sum1
# 	result2 = sum2

# 	for j in range(len(li1) - 2):
# 		sum1 = sum1 - li1[j]
# 		result1 = result1 + sum1
# 	for j in range(len(li2) - 2):
# 		sum2 = sum2 = li2[j]
# 		result2 = result2 + sum2

# 	print(result1+ result2)
# 	# print(sum2)
# 	# print(li1)
# 	# print(li2)


result = li[0] + li[1]
s = result
result = sum(li)
if len(li) >= 2:
	for i in range(2,len(li)):
		result = result + li[i]
		s = s + result


	# s = s - li[i]
	# result = result + s

print(result)
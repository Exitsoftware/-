a = int(input())
b = list(input().split())
c = int(input())
d = list(input().split())

str1 = ""

for c in b:
	str1 = str1 + c

str2 = ""
for c in d:
	str2 = str2 + c




for c in str2:
	if(str1.find(c) == -1):
		print(0)
	else:
		print(1)


# b.sort()

# flag = False
# for i in d:
# 	for j in b:
# 		if(i == j):
# 			flag = True
# 			break
# 		if(i < j):
# 			break
# 	if(flag):
# 		print(1)
# 	else:
# 		print(0)
# 	flag = False



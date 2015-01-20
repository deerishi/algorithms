l=[[836, 100, 274, 931, 632, 817, 951, 992, 17, 349, 189, 99, 77, 316, 698, 10, 732, 3, 2, 445, 524, 343, 953, 513, 459]]
f=open('a.txt','w')
f.write('%d\n'%len(l))
for li in l:
	f.write('%d\n'%len(li))
	for x in li:
		f.write('%d\n'%x)

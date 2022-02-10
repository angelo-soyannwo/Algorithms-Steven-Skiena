

my_list = [(10, "yellow"), (1,"red"), (6, "blue"),(5, "yellow"), (3,"red"), (4,"blue"), (6,"yellow"), (9,"red")]

def color_sort(array):
	n = len(array)
	for i in range(n):
		if array[i][1] == "red":
			j = i
			while j!=0 and array[j-1][1] != "red":
				temp = array[j]
				array[j] = array[j-1]
				array[j-1] = temp

				if j!=0 and (array[j][1] == array[j-1][1]  and array[j][0] < array[j-1][0]):
					temp = array[j]
					array[j] = array[j+1]
					array[j+1] = temp
				j -=1

	print(array)


	for i in range(n):
		if array[i][1] == "blue":
			j = i
			while (j!=0 and array[j-1][1] !=  "red"):
				temp = array[j]
				array[j] = array[j-1]
				array[j-1] = temp
				
				if array[j][1] == array[j-1][1]  and array[j][0] < array[j-1][0]:
					temp = array[j]
					array[j] = array[j-1]
					array[j-1] = temp	
				j -= 1
	print(array)

	for i in range(n):
		if array[i][1] == "yellow":
			j = i
			if array[j][1] == array[j-1][1]  and array[j][0] < array[j-1][0]:
				temp = array[j]
				array[j] = array[j-1]	
				array[j-1] = temp
	print(array)

#			j -=1


color_sort(my_list)

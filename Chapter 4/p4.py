

my_list = [(1, "blue"), (3, "red"), (4,"blue"), (6,"yellow"), (9,"red")] 

#credit to Abdul popoola

#as the list is already sorted by numbers, bucket sort can be used to step through the array and append same colour items to different buckets, without needing to resort any items within buckets.
#
 
#step 1) step through the array and insert each red item into an array and increment the counter r, each blue item into an array and increment the counter b,
# each yellow item into an array and increment the counter y.
#step 2) add all of the values back into the original array starting with reds then blues then yellows.
#
def bucket_color_sort(array):
	red =[]
	r = 0
	blue = []
	b = 0
	yellow = []
	y = 0

	print(array)
	n = len(array)
	for i in range(n):
		if array[i][1] == "red":
			red.append(array[i])
			r +=1

		elif array[i][1] == "blue":
			blue.append(array[i])
			b +=1
			
		elif array[i][1] == "yellow":
			yellow.append(array[i])
			y +=1

	array = []
	for i in range(r):
		array.append(red[i])
	print(array)
	for i in range(b):
		array.append(blue[i-r])

	for i in range(y):
		array.append(yellow[i])

	print(array)

bucket_color_sort(my_list)

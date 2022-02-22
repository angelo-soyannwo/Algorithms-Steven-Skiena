import random

def main():
	elements = ["white","red", "blue", "white", "red", "blue", "white"]

	print(elements)

	def swap(array, i, b):
		temp = array[i]
		array[i] = array[b]
		array[b] = temp

	first_non_red = 0
	for i in range(len(elements)):
		if elements[i] == "red":
			swap(elements, i, first_non_red)
			first_non_red += 1
	print(elements)

	first_non_white = first_non_red
	for i in range(first_non_white, len(elements), 1):
		if elements[i] == "white":
			swap(elements, i, first_non_white)
			first_non_white += 1
	print(elements)

if __name__ == "__main__":
	main()	

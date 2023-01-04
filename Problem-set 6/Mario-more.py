from cs50 import get_int

while True:
    num = get_int("Enter the Height :  ")
    if num > 0 and num < 9:
        break
for i in range(0, num):
    for d in range(0, num + i + 3):
        if (d == num or d == num + 1 or i + d < num - 1):
            print(" ", end = "")
        else:
            print("#", end = "")
    print()

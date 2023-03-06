with open("streetnames.txt") as f:
    a=f.read().strip().split("\n")

for i in a:
    if i[0].islower():
        print(i)

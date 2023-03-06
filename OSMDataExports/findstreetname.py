with open("streetnames.txt" ) as f:
    names = f.read().split("\n")
names.sort()

with open("streetnames_sorted.txt" ,"w") as f:
    f.write(   "\n".join(names))

with open("streetnames_sorted.txt") as f:
    names = f.read().split("\n")

counter=0
for n in names:
    if "a" in n or "g" in n or "p" in n:
        counter+=1
print(counter / len(names))
exit()

prefixes = {}
for length in range(5,6):
    for n in names:
        pre = n[0:length]
        if pre not in prefixes:
            prefixes[pre]=0
        prefixes[pre]+=1
    print(prefixes)

    prefixes = dict(sorted(prefixes.items(),reverse=True, key=lambda item: item[1]))

    import matplotlib.pyplot as plt
    plt.ylabel("frequency")
    plt.xlabel(f"prefix: len={length}")
    plt.bar(prefixes.keys(),prefixes.values())
    plt.show()

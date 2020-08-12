n=int(input())
brides=list(input())
grooms=list(input())
for drink in brides:
    if drink in grooms:
        grooms.remove(drink)
    else:
        break
print(len(grooms))
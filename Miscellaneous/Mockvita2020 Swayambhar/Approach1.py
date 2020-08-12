n=int(input())
brides=input()
grooms=input()
rum_grooms=grooms.count('r')
mojito_grooms=grooms.count('m')
pairs=0
for drinks in brides:
    if drinks=='r':
        if rum_grooms>0:
            rum_grooms-=1
            pairs+=1
        else:
            break
    else:
        if mojito_grooms>0:
            mojito_grooms-=1
            pairs+=1
        else:
            break
print(n-pairs)
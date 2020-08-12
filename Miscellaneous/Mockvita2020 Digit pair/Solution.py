def min_max_digits(number):
    digit1=number%10
    number=int(number/10)
    digit2=number%10
    number = int(number/10)
    digit3=number%10
    number = int(number/10)
    max_digit=max(max(digit1,digit2),digit3)
    min_digit = min(min(digit1, digit2), digit3)
    return max_digit,min_digit
def pairs(num):
    if num>=3:
        return 2
    elif num==2:
        return 1
    return 0
N=int(input())
numbers=list(map(int,input().split()))
bitscores=[]
for number in numbers:
    max_digit,min_digit=min_max_digits(number)
    bitscore=str(max_digit*11 + min_digit*7)[-2:]
    bitscores.append(bitscore)
freq_odd=[0]*10
freq_even=[0]*10
count=[0]*10
for score in bitscores:
    msb=int(score[0])
    if msb%2==0:
        freq_even[msb]+=1
    else:
        freq_odd[msb]+=1
for i in range(10):
    if (freq_even[i]<=1 and freq_odd[i]<=1):
        continue
    count[i]+=int(pairs(freq_even[i])+pairs(freq_odd[i]))
    count[i]=min(2,count[i])
print(sum(count))

import re

with open("./d3.in", 'r', encoding='utf-8') as f:
    data = f.read()

multiply:bool = True

pattern = r"(mul\(\d{1,3},\d{1,3}\)|(do\(\)|don\'t\(\)))"

sum:int = 0

while True:
    instuction = re.search(pattern, data)

    if instuction == None:
        break

    data = data[data.find(instuction.group()) + 4::]

    if instuction.group() == "do()":
        multiply = True
        continue
    elif instuction.group() == "don't()":
        multiply = False
        continue
    elif not multiply:
        continue

    mult = lambda a : int(a[0]) * int(a[1])
    sum += mult(instuction.group()[4:-1:].split(','))

print(sum)
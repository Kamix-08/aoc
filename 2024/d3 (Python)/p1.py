import re

with open("./d3.in", 'r', encoding='utf-8') as f:
    data = f.read()

# could have merged those three lines together, but what's the point?
instuctions = re.findall(r"mul\(\d{1,3},\d{1,3}\)", data)
results = [(int(a) * int(b)) for [a, b] in (x[4:-1:].split(',') for x in instuctions)]
final:int = sum(results)

print(final)
def task1():
    with open("./d2.in", 'r') as f:
        data = f.read()
        
    nums = [x.split('-') for x in data.split(',')]
    
    sum = 0
    used = set()
    
    def int_from_pre(pre: int) -> int: 
        return int(str(pre) * 2)
    
    for a, b in nums:
        if len(a) % 2 != 0:
            a = '1' + ('0' * len(a))
            if int(a) > int(b): continue
            
        ci_pre = int(a[:len(a)//2])
        ci = int_from_pre(ci_pre)
        
        while ci <= int(b):
            if not used.__contains__(ci) and ci > int(a):
                sum += ci
                used.add(ci)
            
            ci_pre += 1
            ci = int_from_pre(ci_pre)
            
    print(sum)
    
def task2():
    with open("./d2.in", 'r') as f:
        data = f.read()
        
    nums = [x.split('-') for x in data.split(',')]
    
    sum = 0
    used = set()
    
    def str_from_pre(pre: int|str, n: int) -> str: 
        return str(pre) * n
    
    for a, b in nums:
        ci_pre = int(a[:len(a)//2]) if len(a) > 1 else 0
        c = str_from_pre(ci_pre, 2)
        
        while int(c) <= int(b):
            for n in range(2, len(c)//2+1):
                d = int(str_from_pre(c[:len(c)//n], n))
                
                if d >= int(a) and d <= int(b) and not used.__contains__(d):
                    sum += d
                    used.add(d)
            
            ci_pre += 1
            c = str_from_pre(ci_pre, 2)
            
    print(sum) # too low
    
# task1()
task2()
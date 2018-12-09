#!/usr/bin/env python3

from subprocess import Popen, PIPE
import sys
import random
import array

#
#

n = int(sys.argv[1]) # how many cases
mode = sys.argv[2] # t for timed r for result
values = sys.argv[3] # r for completly random, d for distinct values, l for large values
size = sys.argv[4]
for i in range(n):
    
    m = 2147483647
    nm = -2147483647

    arr = []

    values = values.lower().strip()
    size = int(size.strip())

    if values == "r":
        for j in range(size):
            arr.append(random.randint(int(nm/2),int(m/2)))
    elif values == "d":
        arr = random.sample(range(-50,100), size)
    elif values == "l":
        arr = random.sample(range(nm, m), size)

    arr_sorted = sorted(arr)
    
    prog = Popen(['./a.out'], shell=True, stdout=PIPE, stdin=PIPE)
    size = str(len(arr)) + '\n'
    size = bytes(size, 'UTF-8') 
    prog.stdin.write(size)
    for q in arr:
        value = str(q) + '\n'
        value = bytes(value, 'UTF-8') 
        prog.stdin.write(value)
    result = list(map(int, prog.communicate()[0].decode("utf-8").rstrip().split(" ")))
    
    
    print("Case " + str(i+1))
    if int(size) < 21:
        print("funSort: " + str(result))
        print("actual:  " + str(arr_sorted))
    if arr_sorted == result:
        print("pass")
    else:
        print("FAIL")
    print("")

#!/usr/bin/env python3

from subprocess import Popen, PIPE
import sys
import random
import array

#
#

n = int(sys.argv[1]) # how many cases
mode = sys.argv[2] # t for timed r for result
values = sys.argv[3] # r for completly random, d for distinct values 

for i in range(n):
    
    
    arr = []
    
    if values.lower().strip() == "r":
        for j in range(5):
            arr.append(random.randint(-3,3))
    else:
        arr = random.sample(range(-50,100), 5)
        
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
    print("funSort: " + str(result))
    print("actual:  " + str(arr_sorted))
    if arr_sorted == result:
        print("pass")
    else:
        print("FAIL")
    print("")

#!/usr/bin/env python3

import subprocess 
import sys
import random
import array
import shlex


n = int(sys.argv[1]) # how many cases
mode = sys.argv[2] # t for timed r for result
values = sys.argv[3] # r for completly random, d for distinct values, l for large values

mode = mode.lower().strip()
values = values.lower().strip()

arr_size = -1

# Choose which make to make
if mode == "t":                        
    subprocess.call(['make', 'timed'])
elif mode == "r" :
    arr_size = int(sys.argv[4])
    subprocess.call('make') # get arr size from user


f = "" # variable name for file if writing to file
if mode == "t":
    f = open("run_time.csv", "w+")

for i in range(1, n + 1):
    # if we are doing timed tests, we want to steadily increase the array size
    if mode == "t":
        arr_size = i
    
    m = 2147483647
    nm = -2147483647

    arr = []
    if values == "r":
        for j in range(arr_size):
            arr.append(random.randint(-50, 50))
    elif values == "d":
        arr = random.sample(range(-arr_size, arr_size), arr_size)
    elif values == "l":
        arr = random.sample(range(-arr_size, arr_size), arr_size)

    arr_sorted = sorted(arr)
    
    prog = subprocess.Popen(['./a.out'], shell=True, stdout=subprocess.PIPE, stdin=subprocess.PIPE)
    size = str(len(arr)) + '\n'
    size = bytes(size, 'UTF-8') 

    # write size of array to fun_sort
    prog.stdin.write(size)
    for q in arr:
        # write array to fun_sort
        value = str(q) + '\n'
        value = bytes(value, 'UTF-8') 
        prog.stdin.write(value)

    # fun_sort now running and waiting for cumminicate
    if mode == "t":
        # fun_sort will return execution time
        result = prog.communicate()[0].decode("utf-8").rstrip()
        f.write(str(i) + "," + result + "\n")
    elif mode == "r":
        result = list(map(int, prog.communicate()[0].decode("utf-8").rstrip().split(" ")))
        print("Case " + str(i+1))
        if arr_size < 21:
            print("funSort: " + str(result))
            print("actual:  " + str(arr_sorted))
        if arr_sorted == result:
            print("pass")
        else:
            print("FAIL")
        print("")

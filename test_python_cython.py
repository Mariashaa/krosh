import timeit

code_to_test = """

import math

m = 50
n = 50
p = 3
def x_py(m, n, p):
    result = 0
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            result += ((i**2 / 5) - math.sin(i**(1/3)) - 5 + math.log(j + 1) 
                       - (5 / (j + 1)**2)**(1/2))**p
    return result**(1/p)
    
answer = x_py(m, n, p)
"""

code_to_test_cython = """
import run_cython

m = 50
n = 50
p = 3.0
answer = run_cython.x_cpy(m, n, p)
"""
elapsed_time = timeit.timeit(code_to_test, number=1000)/1000
elapsed_time_cython = timeit.timeit(code_to_test_cython, number=1000)/1000
print("Python time:", elapsed_time)
print("Cython time:", elapsed_time_cython)

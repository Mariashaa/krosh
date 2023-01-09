from math import sin
from math import log
cpdef double x_cpy(int m, int n, double p):
    cdef double result = 0
    cdef int i
    cdef int j
    for i in range(1, m + 1):
        for j in range(1, n + 1):
            result += ((i**2 / 5) - sin(i**(1/3)) - 5 + log(j + 1) 
                       - (5 / (j + 1)**2)**(1/2))**p
    return result**(1/p)
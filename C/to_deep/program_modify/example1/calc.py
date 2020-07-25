#!/usr/bin/env python
import ctypes as ct 

calc = ct.CDLL('./calc.so')

a = 2
b = 3

print calc.add_num(a, b)
print calc.sub_num(a, b)
print calc.mul_num(a, b)
print calc.div_num(a, b)
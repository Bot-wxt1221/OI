from cyaron import *
import random as r
for i in range (1,21,1):
    io=IO(file_prefix="toy",data_id=i,input_suffix=".in",output_suffix=".out")
    n=r.randint(30000,50000)
    L=r.randint(5000000,10000000)
    io.input_writeln(n,L)
    for j in range(n):
        io.input_write(r.randint(1,10000000), " ")
    io.output_gen("std.exe")

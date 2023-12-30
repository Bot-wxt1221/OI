from cyaron import *
import random
import tqdm

ns=[9,50,1000,1000,1000,1000]+[10**5]*4
ks=[9,50,1000,1000,10**9,10**9]+[10**5]*2+[10**9]*2

for i in tqdm.tqdm(range(0, 20)):
    n = ns[i//2]
    k = ks[i//2]
    k = random.randint(1,k)
    io = IO(file_prefix="color", data_id=i+1)
    io.input_writeln(n,k)
    col=[0]*n
    for i in range(int(n**0.5) if i%2 else n//5):
        col[random.randint(0,n-1)]=random.randint(1,k)
    io.input_writeln(col)
    t = Graph.tree(n, chain=0.1, flower=0.3)
    s = t.to_str(output=
             lambda t:f'{t.start} {t.end}'
             ,shuffle=True)
    io.input_writeln(s)
    io.output_gen("color.exe")
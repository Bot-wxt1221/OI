from cyaron import *
import random
import tqdm

ns=[20,20,400,400,2000,2000,2000]+[10**5]*3

for i in tqdm.tqdm(range(0, 20)):
    n = ns[i//2]
    l=-10**8
    r=10**9
    if i//2==7: l=0
    io = IO(file_prefix="distanced", data_id=i+1)
    up=1000000000//n
    scale_down=random.randint(5,10)
    l=l//scale_down
    r=r//scale_down
    up=up//scale_down
    io.input_writeln(n,up)
    s=set()
    while len(s)<n:
        s.add(random.randint(l,r))
    s=list(s)
    random.shuffle(s)
    io.input_writeln(s)
    def gen():
        x=random.randint(l,r)
        if random.random()<0.3:
            x=random.randint(-10,10)
        return x
    io.input_writeln([gen() for _ in range(n)])
    io.output_gen("distanced")
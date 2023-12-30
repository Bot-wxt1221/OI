from cyaron import *
import random
import tqdm

ns=[40,200,500,350,500]
qs=[40,200,500,10**6,10**6]

for i in tqdm.tqdm(range(0, 20)):
    n = ns[i//4]
    q = qs[i//4]
    io = IO(file_prefix="grid", data_id=i+1)
    g=set()
    r=10**9
    for t in range(n*n//30):
        g.add(random.randint(1,r))
    g=list(g)
    h=set()
    while len(h)<n*n:
        h.add(random.randint(1,r))
    h=list(h)
    h.sort()
    for t in range(n*n//5):
        p,q=random.randint(0,len(h)-1),random.randint(0,len(h)-1)
        h[p],h[q]=h[q],h[p]
    prob=0
    if i//4!=3:
        prob=0.1
    def draw():
        if random.random()<prob:
            return random.choice(g)
        else:
            return h.pop()
    io.input_writeln(n)
    for i in range(n):
        io.input_writeln([draw() for _ in range(n)])
    io.input_writeln(q)
    for i in range(q):
        io.input_writeln(random.randint(1,n),random.randint(1,n))
    io.output_gen("grid.exe")
from cyaron import *
import random
import tqdm

ns=[5,5,100,100,100]+[500]*5
ks=[1,2,3,4,5,6,6,8,8,8]

for i in tqdm.tqdm(range(0, 20)):
    n = ns[i//2]
    k = ks[i//2]
    io = IO(file_prefix="subway", data_id=i+1)
    io.input_writeln(n,k)
    weight_lim = 10000 if i<=5 else 10**9
    weight_l = 10**8 if i>=13 else 1
    def gv():
        R=max(1+weight_l*2,random.choice([weight_lim//100,weight_lim//10,weight_lim]))
        L=min(R,weight_l)
        return random.randint(L,R)
    for _ in range(k):
        io.input_writeln([gv() for _ in range(n)])
        io.input_writeln([gv() for _ in range(n)])
        t = Graph.tree(n,chain=0.3,flower=0.1)
        es = set()
        for e in t.iterate_edges():
            x,y=e.start,e.end
            if x>y: x,y=y,x
            es.add((x,y))
        for u in range(1000-len(es)):
            x,y=random.randint(1,n),random.randint(1,n)
            if x==y: continue
            if x>y: x,y=y,x
            es.add((x,y))
        ee=list(es)
        random.shuffle(ee)
        rm=list(range(n))
        random.shuffle(rm)
        io.input_writeln(len(ee))
        for x,y in ee:
            if random.randint(0,1):
                x,y=y,x
            x=rm[x-1]+1
            y=rm[y-1]+1
            io.input_writeln(x,y,gv())
    io.output_gen("subway")
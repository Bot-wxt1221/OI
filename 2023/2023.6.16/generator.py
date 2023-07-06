from cyaron import *
import random as r
def pq(io,n,minp,maxp,maxq):
    for i in range(n-1):
        io.input_write(r.randint(minp,maxp))
        io.input_write(" ")
    io.input_write('\n')
    for i in range(n-1):
        io.input_write(r.randint(0,maxq))
        io.input_write(" ")
    io.input_write('\n')
def main():
    for i in range(1,2,1):
        io=IO(file_prefix="fish", data_id=i)
        io.input_writeln(5000);
        tree = Graph.tree(5000,weight_limit=400000)
        pq(io,5000,0,1000000,1000000);
        io.input_writeln(tree.to_str(shuffle=True))
        io.output_gen("~/OI/Ventoy/OI/2023/2023.6.16/fish")
    for i in range(2,3,1):
        io=IO(file_prefix="fish", data_id=i)
        io.input_writeln(200000);
        tree = Graph.tree(200000,weight_limit=400000)
        pq(io,200000,0,1000000,0);
        io.input_writeln(tree.to_str(shuffle=True))
        io.output_gen("~/OI/Ventoy/OI/2023/2023.6.16/fish")
    for i in range(3,4,1):
        io=IO(file_prefix="fish", data_id=i)
        io.input_writeln(200000);
        tree = Graph.tree(200000,weight_limit=1)
        pq(io,200000,0,1000000,0);
        io.input_writeln(tree.to_str(shuffle=True))
        io.output_gen("~/OI/Ventoy/OI/2023/2023.6.16/fish")
    for i in range(4,5,1):
        io=IO(file_prefix="fish", data_id=i)
        io.input_writeln(200000);
        tree = Graph.chain(200000,weight_limit=1)
        pq(io,200000,0,1000000,0);
        io.input_writeln(tree.to_str(shuffle=True))
        io.output_gen("~/OI/Ventoy/OI/2023/2023.6.16/fish")
    for i in range(5,7,1):
        io=IO(file_prefix="fish", data_id=i)
        io.input_writeln(200000);
        tree = Graph.tree(200000,weight_limit=400000)
        pq(io,200000,0,1000000,1000000);
        io.input_writeln(tree.to_str(shuffle=True))
        io.output_gen("~/OI/Ventoy/OI/2023/2023.6.16/fish")
    for i in range(7,9,1):
        io=IO(file_prefix="fish", data_id=i)
        io.input_writeln(200000);
        tree = Graph.tree(200000,weight_limit=(100,1000))
        pq(io,200000,200000000,200000001,1000000);
        io.input_writeln(tree.to_str(shuffle=True))
        io.output_gen("~/OI/Ventoy/OI/2023/2023.6.16/fish")
    for i in range(9,11,1):
        io=IO(file_prefix="fish", data_id=i)
        io.input_writeln(200000);
        tree = Graph.chain(200000,weight_limit=400000)
        pq(io,200000,0,1000000,0);
        io.input_writeln(tree.to_str(shuffle=True))
        io.output_gen("~/OI/Ventoy/OI/2023/2023.6.16/fish")
    for i in range(11,13,1):
        io=IO(file_prefix="fish", data_id=i)
        io.input_writeln(200000);
        tree = Graph.chain(200000,weight_limit=1)
        pq(io,200000,0,1000000,1000000);
        io.input_writeln(tree.to_str(shuffle=True))
        io.output_gen("~/OI/Ventoy/OI/2023/2023.6.16/fish")
    for i in range(13,16,1):
        io=IO(file_prefix="fish", data_id=i)
        io.input_writeln(200000);
        tree = Graph.chain(200000,weight_limit=(100,1000))
        pq(io,200000,200000000,200000001,1000000);
        io.input_writeln(tree.to_str(shuffle=True))
        io.output_gen("~/OI/Ventoy/OI/2023/2023.6.16/fish")
    for i in range(16,26,1):
        io=IO(file_prefix="fish", data_id=i)
        io.input_writeln(200000);
        tree = Graph.tree(200000,weight_limit=400000)
        pq(io,200000,0,1000000,1000000);
        io.input_writeln(tree.to_str(shuffle=True))
        io.output_gen("~/OI/Ventoy/OI/2023/2023.6.16/fish")
main()
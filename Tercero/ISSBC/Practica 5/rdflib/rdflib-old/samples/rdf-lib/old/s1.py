from rdflib.Graph import Graph
g = Graph()
g.parse("demo.nt", format="nt")
len(g)
for stmt in g:
     print stmt ,'\n'
print g.serialize()

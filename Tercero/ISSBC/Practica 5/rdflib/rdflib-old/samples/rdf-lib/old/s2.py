from rdflib.Graph import Graph
g = Graph()
g.parse("identificacion-personajes-01.rdf", format="xml")
len(g)
for stmt in g:
     print stmt ,'\n'
print g.serialize()

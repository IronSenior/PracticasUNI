#! /usr/bin/python
# makeTriples.py: demonstrate the creation of an RDFLib TripleStore
#******************************************************************
#           Ejercicio para probar metodos de la clase Graph  ******
#             -objects, predicates, subjects                 ******
#******************************************************************

from rdflib import Namespace, BNode, Literal, URIRef
from rdflib import Graph, ConjunctiveGraph
from rdflib.store.IOMemory import IOMemory

ns = Namespace("http://love.com#")

mary = URIRef("http://love.com/lovers/mary#")
john = URIRef("http://love.com/lovers/john#")

cmary=URIRef("http://love.com/lovers/mary#")
cjohn=URIRef("http://love.com/lovers/john#")

store = IOMemory()

g = ConjunctiveGraph(store=store)
g.bind("love",ns)

gmary = Graph(store=store, identifier=cmary)

gmary.add((mary, ns['hasName'], Literal("Mary")))
gmary.add((mary, ns['loves'], john))

gjohn = Graph(store=store, identifier=cjohn)
gjohn.add((john, ns['hasName'], Literal("John")))

print 'enumerate contexts'
print '===================='
for c in g.contexts():
    print "-- %s " % c




print '#separate graphs'
print '===================='

#separate graphs
print gjohn.serialize(format='n3')
print "==================="
print gmary.serialize(format='n3')
print "==================="

#full graph
print g.serialize(format='n3')

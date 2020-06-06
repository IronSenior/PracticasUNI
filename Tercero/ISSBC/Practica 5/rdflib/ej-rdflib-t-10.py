# -*- coding: utf-8 -*-
"""
Created on Thu Mar 29 09:48:22 2018

@author: acalvo
"""

'''
Adding Triples

We already saw in Loading and saving RDF, how triples can be added with with the parse() function.

Triples can also be added with the add() function:

Graph.add()

    Add a triple with self as context

add() takes a 3-tuple of RDFLib nodes. Try the following with the nodes and namespaces we defined previously:
'''
from rdflib import Namespace
from rdflib import Graph
from rdflib.namespace import RDF, FOAF
from rdflib import URIRef, BNode, Literal

bob = URIRef("http://example.org/people/Bob")
linda = BNode() # a GUID is generated

if False:
    name = Literal('Bob') # passing a string
    age = Literal(24) # passing a python int
    height = Literal(76.5) # passing a python float
    
    g = Graph()
    
    g.add( (bob, RDF.type, FOAF.Person) )
    g.add( (bob, FOAF.name, name) )
    g.add( (bob, FOAF.knows, linda) )
    g.add( (linda, RDF.type, FOAF.Person) )
    g.add( (linda, FOAF.name, Literal('Linda') ) )
    
    print g.serialize(format='turtle')
    '''
 Basic Triple Matching

Instead of iterating through all triples, RDFLib graphs support basic triple 
pattern matching with a triples() function. This function is a generator of 
triples that match the pattern given by the arguments. 
The arguments of these are RDF terms that restrict the 
triples that are returned. Terms that are None are treated as a wildcard. For example:
'''
#g.load("some_foaf.rdf")

g = Graph()
#g.parse("demo.nt", format="nt")
g.parse("http://www.w3.org/People/Berners-Lee/card")
for s,p,o in g.triples( (None, RDF.type, FOAF.Person) ):
   print "%s is a person"%s

for s,p,o in g.triples( (None,  RDF.type, None) ):
   print "%s is a %s"%(s,o)

#bobgraph = Graph()

#bobgraph += g.triples( (bob, None, None) )


print 'subjects'
print '========='


'''
If you are not interested in whole triples, you can get only the bits you want with 
the methods objects(), subjects(), predicates(), predicates_objects(), etc. Each take 
parameters for the components of the triple to constraint:
'''
for person in g.subjects(RDF.type, FOAF.Person):
   print "%s is a person"%person

'''Finally, for some properties, only one value per resource makes sense (i.e they are functional properties, 
or have max-cardinality of 1). The value() method is useful 
for this, as it returns just a single node, not a generator:
'''
name = g.value(bob, FOAF.name) # get any name of bob
print
print name
# get the one person that knows bob and raise an exception if more are found
mbox = g.value(predicate = FOAF.name, object = bob, any = False)



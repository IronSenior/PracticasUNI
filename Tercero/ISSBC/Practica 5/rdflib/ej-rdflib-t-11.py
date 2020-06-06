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

if True:
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
 
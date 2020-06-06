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
outputs:

@prefix foaf: <http://xmlns.com/foaf/0.1/> .
@prefix rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .
@prefix xml: <http://www.w3.org/XML/1998/namespace> .

<http://example.org/people/Bob> a foaf:Person ;
        foaf:knows [ a foaf:Person ;
                        foaf:name "Linda" ] ;
        foaf:name "Bob" .

'''


'''
rdflib.graph.Graph.value() is the matching query method, 
it will return a single value for a property, 
optionally raising an exception if there are more.

'''

g.add( ( bob, FOAF.age, Literal(42) ) )
print "Bob is ", g.value( bob, FOAF.age )
# prints: Bob is 42

g.set( ( bob, FOAF.age, Literal(43) ) ) # replaces 42 set above
print "Bob is now ", g.value( bob, FOAF.age )
# prints: Bob is now 43


'''
Removing Triples

Similarly, triples can be removed by a call to remove():

Graph.remove()[source]

    Remove a triple from the graph

    If the triple does not provide a context attribute, removes the triple from all contexts.

When removing, it is possible to leave parts of the triple unspecified (i.e. passing None), this will remove all matching triples:
'''
g.remove( (bob, None, None) ) # remove all triples about bob

print g.serialize(format='turtle')

'''

La salida es: 

@prefix ns1: <http://xmlns.com/foaf/0.1/> .
@prefix rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#> .
@prefix rdfs: <http://www.w3.org/2000/01/rdf-schema#> .
@prefix xml: <http://www.w3.org/XML/1998/namespace> .
@prefix xsd: <http://www.w3.org/2001/XMLSchema#> .

[] a ns1:Person ;
    ns1:name "Linda" .

'''
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
Navigating Graphs

An RDF Graph is a set of RDF triples, and we try to mirror exactly this in RDFLib, and the graph tries to emulate a container type:
Graphs as Iterators

RDFLib graphs override __iter__() in order to support iteration over the contained triples:
'''
print 'Navigating Graphs'
print '================='
for subject,predicate,obj in g:
   if not (subject,predicate,obj) in g:
      raise Exception("Iterator / Container Protocols are Broken!!")
   print  subject,predicate,obj 


print 
print 'Contains check'
print 

'''Graphs implement __contains__(), so you can check if a 
triple is in a graph with triple in graph syntax:'''


 
if ( bob, RDF.type, FOAF.Person ) in g:
   print "This graph knows that Bob is a person!"
   
if (bob, None, None) in g:
   print "This graph contains triples about Bob!"



 
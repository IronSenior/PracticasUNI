# -*- coding: utf-8 -*-
from rdflib import Graph
from rdflib import URIRef, BNode, Literal, Namespace
from rdflib.namespace import RDF, FOAF

n = Namespace("http://example.org/people/")

n.bob # = rdflib.term.URIRef(u'http://example.org/people/bob')
n.eve # = rdflib.term.URIRef(u'http://example.org/people/eve')

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

print 
print g.serialize(format='turtle')
print 
print g.serialize(format='xml')

print 
print g.serialize(format='n3')

print

print n.bob, n.eve

#print RDF.type

#print FOAF.knows
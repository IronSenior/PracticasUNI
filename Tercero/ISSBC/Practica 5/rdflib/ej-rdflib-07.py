# -*- coding: utf-8 -*-
"""
Created on Thu Mar  5 11:36:21 2015

@author: acalvo
"""

from rdflib import URIRef, BNode, Literal, Namespace, Graph
from rdflib.namespace import RDF, FOAF


bob = URIRef("http://example.org/people/Bob")
linda = BNode() # a GUID is generated

name = Literal('Bob') # passing a string
age = Literal(24) # passing a python int
height = Literal(76.5) # passing a python float

print bob
print name

n = Namespace("http://example.org/people/")

n.bob # = rdflib.term.URIRef(u'http://example.org/people/bob')
n.eve # = rdflib.term.URIRef(u'http://example.org/people/eve')

print 'n.bob, n.eve: ', n.bob, n.eve

print 'RDF.type: ', RDF.type
print 

print 'FOAF.knows: ', FOAF.knows
print 

g=Graph()
g.add((linda,n.loves,bob))
print( g.serialize(format='xml') )
print 
print 
print( g.serialize(format='n3') )

# -*- coding: utf-8 -*-
"""
Created on Thu Mar  5 11:36:21 2015

@author: acalvo
"""

import rdflib

#from rdflib import Graph

g = rdflib.Graph()
g.parse("demo.nt", format="nt")

print len(g) # prints 2

import pprint
for stmt in g:
    pprint.pprint(stmt)

# prints :
(rdflib.term.URIRef('http://bigasterisk.com/foaf.rdf#drewp'),
 rdflib.term.URIRef('http://example.com/says'),
 rdflib.term.Literal(u'Hello world'))
(rdflib.term.URIRef('http://bigasterisk.com/foaf.rdf#drewp'),
 rdflib.term.URIRef('http://www.w3.org/1999/02/22-rdf-syntax-ns#type'),
 rdflib.term.URIRef('http://xmlns.com/foaf/0.1/Person'))

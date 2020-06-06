# -*- coding: utf-8 -*-
"""
Created on Thu Mar 29 09:36:00 2018

@author: acalvo
"""
'''
<http://bigasterisk.com/foaf.rdf#drewp> <http://www.w3.org/1999/02/22-rdf-syntax-ns#type> <http://xmlns.com/foaf/0.1/Person> .
<http://bigasterisk.com/foaf.rdf#drewp> <http://example.com/says> "Hello world" .
'''
from rdflib import Graph

g = Graph()
g.parse("demo.nt", format="nt")

print len(g) # prints 2

import pprint
for stmt in g:
    pprint.pprint(stmt)

 
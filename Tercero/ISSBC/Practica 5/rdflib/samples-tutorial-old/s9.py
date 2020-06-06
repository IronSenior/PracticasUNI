# -*- coding: utf-8 -*-
"""
Created on Wed Mar 18 20:42:10 2015

@author: acalvo
"""

q = prepareQuery(
        'SELECT ?s WHERE { ?person foaf:knows ?s .}',
        initNs = { "foaf": FOAF })

g = rdflib.Graph()
g.load("foaf.rdf")

tim = rdflib.URIRef("http://www.w3.org/People/Berners-Lee/card#i")

for row in g.query(q, initBindings={'person': tim}):
        print row
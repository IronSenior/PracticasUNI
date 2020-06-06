# -*- coding: utf-8 -*-
"""
Created on Wed Mar 18 20:48:49 2015

@author: acalvo
"""

import rdflib

g = rdflib.Graph()
has_border_with = rdflib.URIRef('http://www.example.org/has_border_with')
located_in = rdflib.URIRef('http://www.example.org/located_in')

germany = rdflib.URIRef('http://www.example.org/country1')
france = rdflib.URIRef('http://www.example.org/country2')
china = rdflib.URIRef('http://www.example.org/country3')
mongolia = rdflib.URIRef('http://www.example.org/country4')

europa = rdflib.URIRef('http://www.example.org/part1')
asia = rdflib.URIRef('http://www.example.org/part2')

g.add((germany,has_border_with,france))
g.add((china,has_border_with,mongolia))
g.add((germany,located_in,europa))
g.add((france,located_in,europa))
g.add((china,located_in,asia))
g.add((mongolia,located_in,asia))

q = "select ?country where { ?country <http://www.example.org/located_in> <http://www.example.org/part1> }"
x = g.query(q)
print list(x)
# write graph to file, re-read it and query the newly created graph
g.serialize("graph.rdf")
g1 = rdflib.Graph()
g1.parse("graph.rdf", format="xml")
x1 = g1.query(q)
print list(x1)
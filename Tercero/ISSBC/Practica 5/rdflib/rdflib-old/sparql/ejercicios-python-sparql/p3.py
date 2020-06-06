#!/usr/bin/env python
# -*- coding: iso-8859-1 -*-
from rdflib import ConjunctiveGraph, plugin, Literal, Graph
from rdflib.store import Store
from StringIO import StringIO
import unittest

test_data = """ 
@prefix foaf:       <http://xmlns.com/foaf/0.1/> .
@prefix rdf:        <http://www.w3.org/1999/02/22-rdf-syntax-ns#> .

<http://example.org/bob>  foaf:name       "Bob" .
<http://example.org/dave>  foaf:name       "Dave" .
<http://example.org/alice>  foaf:name       "Alice" .
<http://example.org/charlie>  foaf:name       "Charlie" .
"""

test_query = """
PREFIX foaf: <http://xmlns.com/foaf/0.1/>

SELECT ?name
WHERE { ?x foaf:name ?name . }
ORDER BY ?name
"""

graph= Graph()
#graph = ConjunctiveGraph(plugin.get('IOMemory',Store)())
graph.parse(StringIO(test_data), format="n3")
results = graph.query(test_query)
print graph.serialize(format='xml')
print "el resultado es: ",results
print results.serialize(format="xml")
print '---------------'
print str(results.__str__())
 
f=open(name='salida.xml', mode='w')
f.write(results.serialize(format="xml"))
f.close()
print '==================='
for row in results:
    print row.name
 

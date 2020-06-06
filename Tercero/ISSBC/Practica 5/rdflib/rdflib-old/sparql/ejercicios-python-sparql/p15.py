from rdflib.Namespace import Namespace
from rdflib import plugin,RDF,RDFS,URIRef, StringInputSource, Literal
from rdflib.Graph import Graph,ReadOnlyGraphAggregate,ConjunctiveGraph
from rdflib.store import Store
from StringIO import StringIO
import sys
from pprint import pprint

 
text="""
@prefix dt:   <http://example.org/datatype#> .
@prefix ns:   <http://example.org/ns#> .
@prefix :     <http://example.org/ns#> .
@prefix xsd:  <http://www.w3.org/2001/XMLSchema#> .

:x   ns:p     "42"^^xsd:integer .
:y   ns:p     "abc"^^dt:specialDatatype .
:z   ns:p     "cat"@en .
"""

test_query = """
SELECT ?v WHERE { ?v ?p 42 }
""" 
 
graph = ConjunctiveGraph(plugin.get('IOMemory',Store)())
graph.parse(StringIO(text), format="n3")
print graph.serialize(format='xml')

print
print 'query 3.1.2 Matching Integers:'
print 
results = graph.query(test_query)
print results.serialize(format='xml')

print
print 'query 3.1.2 Matching Arbitrary Datatypes:'
print 
test_query = """
SELECT ?v WHERE { ?v ?p "abc"^^<http://example.org/datatype#specialDatatype> }
""" 
print 
results = graph.query(test_query)
print results.serialize(format='xml')

print
print 'query 3.1.2 Matching Laguages Tag:'
print 
test_query = """
 SELECT ?x WHERE {
        ?x ?p ?title .
   FILTER (regex(str(?title), "cat"))
 }
""" 
print 
results = graph.query(test_query)
pprint(results.serialize(format='xml'))






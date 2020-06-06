from rdflib import Namespace
from rdflib import plugin,RDF,RDFS,URIRef, Literal
from rdflib  import Graph,ConjunctiveGraph
from rdflib.store import Store
from StringIO import StringIO
import sys
from pprint import pprint

 
text="""
@prefix rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#> .
@prefix dc:  <http://purl.org/dc/elements/1.1/> .
@prefix :    <http://example/ns#> .

_:a   rdf:subject   <http://example.org/book/book1> .
_:a   rdf:predicate dc:title .
_:a   rdf:object    "SPARQL" .
_:a   :saidBy       "Alice" .

_:b   rdf:subject   <http://example.org/book/book1> .
_:b   rdf:predicate dc:title .
_:b   rdf:object    "SPARQL Tutorial" .
_:b   :saidBy       "Bob" .
"""

test_query = """
PREFIX dc: <http://purl.org/dc/elements/1.1/>

SELECT ?book ?title
WHERE
{ ?book dc:title ?title }
""" 
 
graph = ConjunctiveGraph(plugin.get('IOMemory',Store)())
graph.parse(StringIO(text), format="n3")
print graph.serialize(format='xml')

print 
results = graph.query(test_query)

print results.serialize(format='xml')


for row in results:
    print row.book, row.title


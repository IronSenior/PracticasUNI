from rdflib.Namespace import Namespace
from rdflib import plugin,RDF,RDFS,URIRef, StringInputSource, Literal
from rdflib.Graph import Graph,ReadOnlyGraphAggregate,ConjunctiveGraph
from rdflib.store import Store
from StringIO import StringIO
import sys
from pprint import pprint

 
text="""
@prefix dc:   <http://purl.org/dc/elements/1.1/> .
@prefix :     <http://example.org/book/> .
:book1  dc:title  "SPARQL Tutorial" .
"""

test_query = """
BASE    <http://example.org/book/>
PREFIX  dcore:  <http://purl.org/dc/elements/1.1/>
SELECT  ?title
WHERE   { :book1 dcore:title ?title }
""" 
 
graph = ConjunctiveGraph(plugin.get('IOMemory',Store)())
graph.parse(StringIO(text), format="n3")
print graph.serialize(format='xml')

print 
results = graph.query(test_query)
print results.serialize(format='xml')




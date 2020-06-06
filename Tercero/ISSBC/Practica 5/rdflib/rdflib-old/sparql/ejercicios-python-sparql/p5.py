'''from rdflib.Namespace import Namespace
from rdflib import plugin,RDF,RDFS,URIRef, StringInputSource, Literal
from rdflib.Graph import Graph,ReadOnlyGraphAggregate,ConjunctiveGraph
from rdflib.store import Store
from StringIO import StringIO
import sys
from pprint import pprint
'''
from rdflib import ConjunctiveGraph, plugin, Literal, Graph
from rdflib.store import Store
from StringIO import StringIO
import unittest

text="""
<http://example.org/book/book1> <http://purl.org/dc/elements/1.1/title>
"SPARQL Tutorial" .
"""

test_query = """
SELECT ?title
WHERE
{
  <http://example.org/book/book1> <http://purl.org/dc/elements/1.1/title> ?title .
}
""" 
 
graph = ConjunctiveGraph(plugin.get('IOMemory',Store)())
graph.parse(StringIO(text), format="n3")
print graph.serialize(format='xml')


print 
results = graph.query(test_query)
print results.serialize(format='xml')




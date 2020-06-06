from rdflib import Namespace
from rdflib import plugin,RDF,RDFS,URIRef,  Literal
from rdflib import Graph,ConjunctiveGraph
from rdflib.store import Store
from StringIO import StringIO
import sys
from pprint import pprint

 
text="""
@prefix foaf:    <http://xmlns.com/foaf/0.1/> .

_:a  foaf:name   "Johnny Lee Outlaw" .
_:a  foaf:mbox   <mailto:outlaw@example.com> .

_:b  foaf:name   "A. N. Other" .
_:b  foaf:mbox   <mailto:other@example.com> .
"""

test_query = """
PREFIX foaf:   <http://xmlns.com/foaf/0.1/>
SELECT ?mbox
WHERE
  { ?x foaf:name "Johnny Lee Outlaw" .
    ?x foaf:mbox ?mbox }
""" 
 
graph = ConjunctiveGraph(plugin.get('IOMemory',Store)())
graph.parse(StringIO(text), format="n3")
print graph.serialize(format='xml')

print 
results = graph.query(test_query)
#print results.serialize(format='xml')

for row in results:
    print row.mbox


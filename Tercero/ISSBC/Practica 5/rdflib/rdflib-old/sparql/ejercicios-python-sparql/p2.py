from rdflib import ConjunctiveGraph, plugin, Literal, Graph
from rdflib.store import Store
from StringIO import StringIO
import unittest

test_data = """ 
@prefix foaf:       <http://xmlns.com/foaf/0.1/> .
@prefix rdf:        <http://www.w3.org/1999/02/22-rdf-syntax-ns#> .

<http://example.org/bob>     foaf:name       "Bob" .
<http://example.org/bob>     foaf:mbox      <mailto:outlaw@example.com> .
<http://example.org/bob>     foaf:edad      30 .

<http://example.org/dave>    foaf:name       "Dave" .
<http://example.org/dave>     foaf:edad      18 .


<http://example.org/alice>   foaf:name       "Alice" .
<http://example.org/alice>   foaf:mbox   <mailto:other@example.com> .
<http://example.org/alice>     foaf:edad      20 .


<http://example.org/charlie>  foaf:name       "Charlie" .
<http://example.org/charlie>     foaf:edad      25 .


"""

test_query = """
PREFIX foaf: <http://xmlns.com/foaf/0.1/>

SELECT ?name
WHERE { ?x foaf:name ?name . }
ORDER BY ?name
"""


graph = ConjunctiveGraph(plugin.get('IOMemory',Store)())
#graph=Graph()
graph.parse(StringIO(test_data), format="n3")
print graph.serialize(format='xml')
print 
results = graph.query(test_query)
print results.serialize(format='xml')


print '-----------------------------------------------------'

def consulta_1(graph):
    test_query = """
    PREFIX foaf: <http://xmlns.com/foaf/0.1/>

    SELECT ?name
    WHERE { <http://example.org/bob>  foaf:name ?name . }
    ORDER BY ?name
    """

    print 
    results = graph.query(test_query)
    #print results.serialize(format='xml')
    return

def consulta_2(graph):
    print '-----------------------------------------------------'

    test_query = """
    PREFIX foaf: <http://xmlns.com/foaf/0.1/>

    SELECT ?s
    WHERE { ?s foaf:name "Bob" . }
    """

    print 
    results = graph.query(test_query)
    #print results.serialize(format='xml')

def consulta_3(graph):
    print '-----------------------------------------------------'

    test_query = """
    PREFIX foaf: <http://xmlns.com/foaf/0.1/>

    SELECT ?mbox
    WHERE { ?s foaf:name "Bob" .
            ?s foaf:mbox ?mbox
          }
    """


    print 
    results = graph.query(test_query)
    print results.serialize(format='xml')

def consulta_4(graph):
    test_query = """
    PREFIX foaf: <http://xmlns.com/foaf/0.1/>

    SELECT ?name ?edad
    WHERE { ?x foaf:name ?name .
            ?x foaf:edad ?edad 
     
          }
    """

    print 
    results = graph.query(test_query)
    print results.serialize(format='xml')
if __name__ == '__main__':

     #consulta_1(graph)
     #consulta_2(graph)
     #consulta_3(graph)
     consulta_4(graph)


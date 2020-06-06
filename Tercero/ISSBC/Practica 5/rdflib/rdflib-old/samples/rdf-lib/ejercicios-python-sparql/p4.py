#!/usr/bin/env python
# -*- coding: utf-8 -*-
from rdflib import Namespace
from rdflib import plugin,RDF,RDFS,URIRef,  Literal
from rdflib import Graph,ConjunctiveGraph
from rdflib.store import Store
from StringIO import StringIO
import sys
from pprint import pprint

text="""
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

text1="""
@prefix dc:       <http://purl.org/dc/elements/1.1/> .
<http://example.org/a>   dc:title       "That Seventies Show"@en  .
<http://example.org/b>   dc:title         "Cette Série des Années Soixante-dix" .
<http://example.org/c>   dc:title         "Cette Série des Années Septante" .
<http://example.org/d>   dc:title         "Il Buono, il Bruto, il Cattivo" .

"""

text2="""
@prefix dc:       <http://purl.org/dc/elements/1.1/> .
@prefix or:        <http://example.org/> .
or:a   dc:title       "That Seventies Show"@en  .
or:a   dc:title         "Cette Série des Années Soixante-dix"@fr .
or:c   dc:title         "Cette Série des Années Septante"@it .
or:d   dc:title         "Il Buono, il Bruto, il Cattivo"@pt .

"""

test_query = """
PREFIX dc: <http://purl.org/dc/elements/1.1/>

SELECT ?s 
 WHERE { ?s ?p ?o
       }
""" 
 
graph = ConjunctiveGraph(plugin.get('IOMemory',Store)())
graph.parse(StringIO(text), format="n3")
print graph.serialize(format='xml')


print 
results = graph.query(test_query)
#print results.serialize(format='xml')
for row in results:
    print row.s



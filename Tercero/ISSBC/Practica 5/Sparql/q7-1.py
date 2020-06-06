# -*- coding: utf-8 -*-
"""
Created on Tue Mar 13 10:06:54 2018

@author: acalvo
"""

from rdflib import Graph,Namespace

FOAF = Namespace("http://xmlns.com/foaf/0.1/")
RDFS = Namespace("http://www.w3.org/2000/01/rdf-schema#")


my_data ='''
@prefix foaf:       <http://xmlns.com/foaf/0.1/> .
@prefix rdf:        <http://www.w3.org/1999/02/22-rdf-syntax-ns#> .

_:a  rdf:type        foaf:Person .
_:a  foaf:name       "Alice" .
_:a  foaf:mbox       <mailto:alice@example.com> .
_:a  foaf:mbox       <mailto:alice@work.example> .

_:b  rdf:type        foaf:Person .
_:b  foaf:name       "Bob" .

     '''
g = Graph()
g.parse(data=my_data, format="n3")
print g.serialize(format='xml')



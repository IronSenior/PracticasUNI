# -*- coding: utf-8 -*-
"""
Created on Thu Mar 19 12:57:28 2015

@author: acalvo
"""

from rdflib.namespace import OWL, RDF, RDFS
from rdflib import Graph, Literal, Namespace, URIRef

# Construct the linked data tools namespace
LDT   = Namespace("http://www.linkeddatatools.com/plants#")

# Create the graph
graph = Graph()

# Create the node to add to the Graph
Plant = URIRef(LDT["Planttype"])

# Add the OWL data to the graph
graph.add((Plant, RDF.type, OWL.Class))
graph.add((Plant, RDFS.subClassOf, OWL.Thing))
graph.add((Plant, RDFS.label, Literal("The plant type")))
graph.add((Plant, RDFS.comment, Literal("The class of all plant types")))

# Bind the OWL and LDT name spaces
graph.bind("owl", OWL)
graph.bind("ldt", LDT)

print graph.serialize(format='xml')
print 
print graph.serialize(format='n3')



print

print 'otra forma de presentar'
print graph.serialize(format='pretty-xml')

graph.serialize('sal.owl',format='pretty-xml')
# -*- coding: utf-8 -*-
"""
Created on Wed Mar 18 20:27:34 2015

@author: acalvo
"""
"""

A simple example showing how to use the SPARQLStore

"""

from rdflib import Graph, URIRef, Namespace

if __name__ == '__main__': 

    dbo = Namespace('http://dbpedia.org/ontology/')

    graph = Graph('SPARQLStore') 

    graph.open("http://dbpedia.org/sparql")

    pop = graph.value(
        URIRef("http://dbpedia.org/resource/Berlin"), 
        dbo.populationTotal)

    print "According to DBPedia Berlin has a population of", pop
              


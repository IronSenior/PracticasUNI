# -*- coding: utf-8 -*-
"""
Created on Thu Mar 29 09:44:34 2018

@author: acalvo
"""

#For creating many URIRefs in the same namespace, i.e. URIs with the same prefix, 
#RDFLib has the rdflib.namespace.Namespace class:

from rdflib import Namespace

n = Namespace("http://example.org/people/")

n.bob # = rdflib.term.URIRef(u'http://example.org/people/bob')
n.eve # = rdflib.term.URIRef(u'http://example.org/people/eve')

#This is very useful for schemas where all properties and classes have the same URI prefix, 
#RDFLib pre-defines Namespaces for the most common RDF schemas:

from rdflib.namespace import RDF, FOAF

RDF.type
# = rdflib.term.URIRef(u'http://www.w3.org/1999/02/22-rdf-syntax-ns#type')

FOAF.knows
# = rdflib.term.URIRef(u'http://xmlns.com/foaf/0.1/knows')


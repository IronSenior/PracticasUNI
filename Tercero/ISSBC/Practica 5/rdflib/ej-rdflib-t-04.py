# -*- coding: utf-8 -*-
"""
Created on Thu Mar 29 09:41:05 2018

@author: acalvo
"""
from rdflib import URIRef, BNode, Literal

bob = URIRef("http://example.org/people/Bob")
linda = BNode() # a GUID is generated

name = Literal('Bob') # passing a string
age = Literal(24) # passing a python int
height = Literal(76.5) # passing a python float

print name
print age
print height

#Ver en la consola: name, age, height

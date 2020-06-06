#!/usr/bin/env python
# -*- coding: iso-8859-1 -*-
"""
Created on Thu Mar  5 11:36:21 2015

@author: acalvo
"""

import rdflib #Importa la librería
g=rdflib.Graph() #Crea una instancia de grafo
g.load('http://dbpedia.org/resource/Semantic_Web')


print g.serialize(format="xml") #Muestra un grafo en formato xml

print "_________________________"

for s,p,o in g:
    print s,p,o
    pass
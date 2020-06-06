#!/usr/bin/env python
# -*- coding: iso-8859-1 -*-

#from rdflib import ConjunctiveGraph, 

from rdflib import Graph
from rdflib import Namespace
from rdflib import Literal

FOAF = Namespace("http://xmlns.com/foaf/0.1/")
EX = Namespace("http://example.org/foovocab#")

 
def main():
    #Crea el grafo
    s = Graph()
    #Asocia prefijos al espacio de nombres   en el  grafo
    s.bind('dc',EX)
    s.bind('foaf',FOAF)
    
    #Lee un archivo rdf
    s.parse("exe2.rdf")
    print s.serialize(format="xml")
    #Quién es la secretaria de Bob?

    # Encuentra un tipo llamado Bob...
    print 'Encuentra un indiciduo llamado Bob...'
    for who in s.subjects(FOAF["name"], Literal("Bob")):#sujetos con este predicado y este objeto
        bob = who
        print  'El individuo es:',who
        print 
        
        
    print '==============================='
    # who is secretlyStalking bob?
    print '  Quien es la secretaria de  bob?'
    
    for who in s.subjects(EX["secretlyStalking"], bob):
        for n in s.objects(who, FOAF["name"]):
            print n, "is secretlyStalking Bob!"

if __name__ == '__main__':
    main()

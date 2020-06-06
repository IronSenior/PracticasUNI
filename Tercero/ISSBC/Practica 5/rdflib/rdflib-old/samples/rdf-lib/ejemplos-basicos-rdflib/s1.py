#! /usr/bin/python
# -*- coding: iso-8859-1 -*-

from rdflib import Graph
from rdflib import Namespace
g = Graph()
#g.parse("http://bigasterisk.com/foaf.rdf")
#g.parse("http://www.w3.org/People/Berners-Lee/card.rdf")
#print g.serialize()

 
FOAF = Namespace("http://xmlns.com/foaf/0.1/")
g.parse("http://danbri.livejournal.com/data/foaf")
print g.serialize()

consulta='''SELECT ?aname ?bname
             WHERE { ?a foaf:knows ?b .
                     ?a foaf:name ?aname .
                     ?b foaf:name ?bname . }'''

print g.query(consulta,initNs=dict(foaf=Namespace("http://xmlns.com/foaf/0.1/")))

for row in g.query(consulta,initNs=dict(foaf=Namespace("http://xmlns.com/foaf/0.1/"))):
    print "%s knows %s" % row

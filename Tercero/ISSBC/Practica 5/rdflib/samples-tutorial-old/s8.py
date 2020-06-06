# -*- coding: utf-8 -*-
"""
Created on Wed Mar 18 20:37:17 2015

@author: acalvo
"""

import rdflib

g = rdflib.Graph()

# ... add some triples to g somehow ...
g.parse("foaf.rdf")

qres = g.query(
    """SELECT DISTINCT ?aname ?bname
       WHERE {
          ?a foaf:knows ?b .
          ?a foaf:name ?aname .
          ?b foaf:name ?bname .
       }""")

for row in qres:
    print("%s knows %s" % row)
    #print row
#!/usr/bin/env python
# -*- coding: iso-8859-1 -*-
from rdflib import Graph
g = Graph()
#g.parse("http://bigasterisk.com/foaf.rdf")

#g.parse("demo.nt", format="nt")

#g.parse("http://bigasterisk.com/foaf.rdf")
my_data = '''
<rdf:RDF
   xmlns:rdf='http://www.w3.org/1999/02/22-rdf-syntax-ns#'
   xmlns:rdfs='http://www.w3.org/2000/01/rdf-schema#'>
   <rdf:Description>
     <rdfs:label>Example</rdfs:label>
     <rdfs:comment>This is really just an example.</rdfs:comment>
   </rdf:Description>
 </rdf:RDF>
 '''

import tempfile
file_name = tempfile.mktemp()
f = file(file_name, "w")
f.write(my_data)
f.close()
g = Graph()
result = g.parse(data=my_data, format="application/rdf+xml")
print len(g)


g1 = Graph()
result = g1.parse(location='demo.xml', format="application/rdf+xml")
len(g1)

print g.serialize(format='xml')

g1 = Graph()
#file_name='C:/users/acalvo/pln/ckModAp/pruebas/demo.xml'
file_name='demo.xml'
result = g1.parse(file=file(file_name, "r"), format="application/rdf+xml")
len(g1)

print g.serialize(format='xml')
print 
print g1.serialize(format='xml')

# -*- coding: utf-8 -*-
"""
Created on Thu Mar 29 09:27:31 2018

@author: acalvo
"""

import rdflib

g = rdflib.Graph()
result = g.parse("http://www.w3.org/People/Berners-Lee/card")

print("graph has %s statements." % len(g))
# prints graph has 79 statements.

for subj, pred, obj in g:
   if (subj, pred, obj) not in g:
       raise Exception("It better be!")

s = g.serialize(format='n3')
print s
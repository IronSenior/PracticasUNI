import rdflib

g = rdflib.Graph()
result = g.parse("http://www.w3.org/People/Berners-Lee/card")

print("graph has %s statements." % len(g))
# prints graph has 79 statements.

for subj, pred, obj in g:
    print '--->', subj
    
    if (subj, pred, obj) not in g:
       raise Exception("It better be!")

print 


s = g.serialize(format='n3')

print s




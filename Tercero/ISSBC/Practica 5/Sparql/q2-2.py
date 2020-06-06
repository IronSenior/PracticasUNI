'''
Created on 11/04/2011

@author: acalvo
'''
import rdflib
from rdflib import Graph,Namespace
from rdflib import plugin
FOAF = Namespace("http://xmlns.com/foaf/0.1/")
RDFS = Namespace("http://www.w3.org/2000/01/rdf-schema#")


def q2():
       
    my_data ='''
                @prefix foaf:  <http://xmlns.com/foaf/0.1/> .
                
                _:a  foaf:name   "Johnny Lee Outlaw" .
                _:a  foaf:mbox   <mailto:jlow@example.com> .
                _:b  foaf:name   "Peter Goodguy" .
                _:b  foaf:mbox   <mailto:peter@example.org> .
                _:c  foaf:mbox   <mailto:carol@example.org> .

     '''
    g = Graph()
    g.parse(data=my_data, format="n3")
    print len(g)
    print g.serialize(format='xml')
    print g.serialize(format='n3')
    
    query='''
                SELECT ?name ?mbox
                WHERE
                  { ?x foaf:name ?name .
                    ?x foaf:mbox ?mbox }

''' 
    result=g.query(query,initNs=dict(foaf=Namespace("http://xmlns.com/foaf/0.1/")))
    print 'resultado:'
    for row in result:
        #print row
        print "%s MAIL=====>: %s" % tuple(row)
        
     

if __name__ == '__main__':

    if True:
        print rdflib.__version__ 
        print plugin.__name__
        print
        q2()
        
        
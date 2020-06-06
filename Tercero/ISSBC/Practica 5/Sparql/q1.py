'''
Created on 11/04/2011

@author: acalvo
'''
import rdflib
from rdflib import Graph,Namespace
from rdflib import plugin

FOAF = Namespace("http://xmlns.com/foaf/0.1/")
RDFS = Namespace("http://www.w3.org/2000/01/rdf-schema#")



def q1():   
    my_data ='''
         @prefix dc:   <http://purl.org/dc/elements/1.1/> .
         @prefix :     <http://example.org/book/> .
         :book1  dc:title  "SPARQL Tutorial" .
     '''
    g = Graph()
    result = g.parse(data=my_data, format="n3")
    print 'result',result
    print len(g)
    print g.serialize(format='xml')
    print g.serialize(format='n3')
    
    query='''SELECT ?title
                WHERE
                {
                  <http://example.org/book/book1> <http://purl.org/dc/elements/1.1/title> ?title .
                }  
''' 
    result=g.query(query)
    for row in result:
        print row
        print type(row)
        print "Titulo: %s" % tuple(row)
        
        
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
    #result=g.query(query,initNs=dict(foaf=Namespace("http://xmlns.com/foaf/0.1/")))
    result=g.query(query)
    for row in result:
        #print row
        print "%s tiene de email %s" % tuple(row)
        
     

if __name__ == '__main__':
    
    if False:
        print 
        print 'q1:'
        q1()
    if True:
        print 'q2'
        print rdflib.__version__ 
        print plugin.__name__
        print 
        
        q2()
        
        
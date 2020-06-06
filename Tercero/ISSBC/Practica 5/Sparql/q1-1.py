'''
Created on 11/04/2011

@author: acalvo
'''
import rdflib
from rdflib import Graph,Namespace
FOAF = Namespace("http://xmlns.com/foaf/0.1/")
RDFS = Namespace("http://www.w3.org/2000/01/rdf-schema#")



my_data ='''
        @prefix dc:   <http://purl.org/dc/elements/1.1/> .
        @prefix :     <http://example.org/book/> .
        @prefix ns:   <http://example.org/ns#> .
        
        :book1  dc:title  "SPARQL Tutorial" .
        :book1  ns:price  42 .
        :book2  dc:title  "The Semantic Web" .
        :book2  ns:price  23 .
     '''
g = Graph()
g.parse(data=my_data, format="n3")
print g.serialize(format='xml')

#4.1.1 Syntax for IRIs
def q1():
          
    query='''    
    PREFIX  dc:  <http://purl.org/dc/elements/1.1/>
    SELECT  ?title
    WHERE   { <http://example.org/book/book1> dc:title ?title
                  FILTER regex(?title, "^SPARQL") 
                }
''' 
    result=g.query(query)
    print 'RESULTADO DE LA CONSULTA'
    print '===================='
    print result.serialize()
    print
    for row in result:
        #print row
        print "%s" % row
 
def q2():
          
    query='''
    PREFIX book: <http://example.org/book/>
    PREFIX  dc:  <http://purl.org/dc/elements/1.1/>
    SELECT  ?title
    WHERE   { book:book1 dc:title ?title
                  FILTER regex(?title, "^SPARQL") 
                }
''' 
    result=g.query(query)
    print 'RESULTADO DE LA CONSULTA'
    print '===================='
    print result.serialize()
    print
    for row in result:
        #print row
        print "%s" % row
def q3():
          
    query='''
    BASE <http://example.org/book/>
    PREFIX  dc:  <http://purl.org/dc/elements/1.1/>
    SELECT  ?title
    WHERE   { <book1> dc:title ?title
                  FILTER regex(?title, "^SPARQL") 
                }
''' 
    result=g.query(query)
    print 'RESULTADO DE LA CONSULTA Q3'
    print '===================='
    print result.serialize()
    print
    for row in result:
        #print row
        print "%s" % row
if __name__ == '__main__':

    if True:
        print 'q1:'
        
        q1()
        print 'q2:'
        q2()
        print 'q3:'
        q3()

        
        
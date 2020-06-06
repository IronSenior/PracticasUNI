'''
Created on 11/04/2011

@author: acalvo
'''
import rdflib
from rdflib import Graph,Namespace
from rdflib import plugin
FOAF = Namespace("http://xmlns.com/foaf/0.1/")
RDFS = Namespace("http://www.w3.org/2000/01/rdf-schema#")


my_data ='''
@prefix foaf:       <http://xmlns.com/foaf/0.1/> .
@prefix rdf:        <http://www.w3.org/1999/02/22-rdf-syntax-ns#> .

_:a  rdf:type        foaf:Person .
_:a  foaf:name       "Alice" .
_:a  foaf:mbox       <mailto:alice@example.com> .
_:a  foaf:mbox       <mailto:alice@work.example> .

_:b  rdf:type        foaf:Person .
_:b  foaf:name       "Bob" .

     '''
g = Graph()
g.parse(data=my_data, format="n3")
print g.serialize(format='xml')

#4.1.1 Syntax for IRIs
def q1():
          
    query='''    
PREFIX foaf: <http://xmlns.com/foaf/0.1/>
SELECT ?name ?mbox
WHERE  { ?x foaf:name  ?name .
         OPTIONAL { ?x  foaf:mbox  ?mbox }
       }

''' 
    result=g.query(query)
    print 'RESULTADO DE LA CONSULTA Q1'
    print '===================='
    #print result.serialize()
    print
    for row in result:
        #print row
        print "%s %s " % tuple(row)
 
def q2():
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
          
    query='''
PREFIX  dc:  <http://purl.org/dc/elements/1.1/>
PREFIX  ns:  <http://example.org/ns#>
SELECT  ?title ?price
WHERE   { ?x dc:title ?title .
          OPTIONAL { ?x ns:price ?price . FILTER (?price < 30) }

        }

''' 
    result=g.query(query)
    print 'RESULTADO DE LA CONSULTA q2'
    print '===================='
    #print result.serialize()
    print len(result)
    for row in result:
        #print row
        print "%s %s " % tuple(row)
def q3():
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
    #Ver http://skos.um.es/TR/rdf-sparql-query/#QSynBlankNodes
    query='''
    PREFIX  dc:  <http://purl.org/dc/elements/1.1/>
    PREFIX  ns:  <http://example.org/ns#>
    
    SELECT  ?title
    WHERE   {?x dc:title ?title 
             FILTER regex(?title, "^SPARQL") 
    
    }
''' 
    result=g.query(query)
    print 'RESULTADO DE LA CONSULTA Q3'
    print '===================='
    #print result.serialize()
    print
    for row in result:
        #print row
        print "%s" % tuple(row)
if __name__ == '__main__':
    if True:
        q1()
        q2()
        q3()

        
        
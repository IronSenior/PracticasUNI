'''
Created on 11/04/2011

@author: acalvo
'''
import rdflib
from rdflib import Graph,Namespace
from rdflib import plugin
FOAF = Namespace("http://xmlns.com/foaf/0.1/")
RDFS = Namespace("http://www.w3.org/2000/01/rdf-schema#")

if False:
    plugin.register(
        'sparql', rdflib.query.Processor,
        'rdfextras.sparql.processor', 'Processor')
    plugin.register(
        'sparql', rdflib.query.Result,
        'rdfextras.sparql.query', 'SPARQLQueryResult')

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

#2.5 Filtering RDF Graphs
def q1():
          
    query='''    
        PREFIX  dc:  <http://purl.org/dc/elements/1.1/>
        SELECT  ?title
        WHERE   { ?x dc:title ?title
                  FILTER regex(?title, "^SPARQL") 
                }
''' 
    result=g.query(query)
    print 'RESULTADO DE LA CONSULTA q1'
    print '===================='
    print result.serialize()
    print
    for row in result:
        #print row
        print "%s" % row
#3.2 Restricting Numeric Values
def q2():
          
    query='''    
        PREFIX  dc:  <http://purl.org/dc/elements/1.1/>
        PREFIX  ns:  <http://example.org/ns#>
        SELECT  ?title ?price
        WHERE   { ?x ns:price ?price .
                  FILTER (?price < 45.5)
                  ?x dc:title ?title . }
''' 
    result=g.query(query)
    print 'RESULTADO DE LA CONSULTA q2'
    print '===================='
    print result.serialize()
    print
    for row in result:
        #print row
        print "%s %s" % tuple(row)
        print type(row),row[0],'==>',row[1]

if __name__ == '__main__':

    if True:
        print 'q1:'
        q1()
        print 'q2:'
        q2()

        
        
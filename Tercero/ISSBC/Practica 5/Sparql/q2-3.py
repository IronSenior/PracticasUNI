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
                @prefix dt:   <http://example.org/datatype#> .
                @prefix ns:   <http://example.org/ns#> .
                @prefix :     <http://example.org/ns#> .
                @prefix xsd:  <http://www.w3.org/2001/XMLSchema#> .
                
                :x   ns:p     "cat"@en .
                :y   ns:p     "42"^^xsd:integer .
                :z   ns:p     "abc"^^dt:specialDatatype .


     '''
g = Graph()
g.parse(data=my_data, format="n3")
    #print 'result',result
    #print len(g)
print g.serialize(format='xml')
    #print g.serialize(format='n3')


#2.3 Matching RDF Literals
def q1():
          
    query='''    
                 PREFIX dt:   <http://example.org/datatype#> 
                 PREFIX ns:   <http://example.org/ns#> 
                 PREFIX xsd: <http://www.w3.org/2001/XMLSchema#>
                 PREFIX :     <http://example.org/ns#> 
                 
                 
                SELECT ?s WHERE { ?s ?p "cat"@en }


''' 
    result=g.query(query)
    print result
    for row in result:
        #print row
        print "%s" % row
        
def q2():   
    query='''    
                 PREFIX dt:   <http://example.org/datatype#> 
                 PREFIX ns:   <http://example.org/ns#> 
                 PREFIX xsd: <http://www.w3.org/2001/XMLSchema#>
                 PREFIX :     <http://example.org/ns#> 
                 
                 
                SELECT ?s WHERE { ?s ?p 42 }


''' 
    result=g.query(query)
    print result
    for row in result:
        #print row
        print "Sujeto: %s" % row
     
def q3():   
    query='''    
                 PREFIX dt:   <http://example.org/datatype#> 
                 PREFIX ns:   <http://example.org/ns#> 
                 PREFIX xsd: <http://www.w3.org/2001/XMLSchema#>
                 PREFIX :     <http://example.org/ns#>              
                SELECT ?s WHERE { ?s ?p "abc"^^<http://example.org/datatype#specialDatatype> }
''' 




    result=g.query(query)
    print result
    for row in result:
        #print row
        print "Sujeto: %s" % row

if __name__ == '__main__':

    if True:
        print 'q1:'
        print
        q1()
        print 'q2:'
        print
        q2()
        print 'q3:'
        print
        q3()
        
        
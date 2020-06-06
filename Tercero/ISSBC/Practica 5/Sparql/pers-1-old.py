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
    

def q1():   
    my_data ='''
         @prefix dc:   <http://purl.org/dc/elements/1.1/> .
         @prefix :     <http://example.org/book/> .
         :book1  dc:title  "SPARQL Tutorial" .
     '''
    g = Graph()
    result = g.parse('/Users/acalvo/DropBox/iaic/ontologies/personas.owl')

    #print g.serialize(format='n3')
    g.parse('/Users/acalvo/DropBox/iaic/ontologies/instPersonas.owl')
    print 'result',result
    print len(g)
    print g.serialize(format='xml')

    if False:
        query='''
            PREFIX per: <http://www.uco.es/iaic/ontologies/personas.owl#>
            PREFIX instP: <http://www.semanticweb.org/ontologies/instPersonas.owl#>
    
            SELECT   ?s
                    WHERE
                    {
                      ?s per:residencia Literal('Cordoba') <http://www.w3.org/2001/XMLSchema#string>
                    }  
    ''' 
        result=g.query(query)
        for row in result:
            print row
          

if __name__ == '__main__':
    
    if True:
        q1()

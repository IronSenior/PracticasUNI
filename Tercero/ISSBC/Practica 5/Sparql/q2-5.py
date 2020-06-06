'''
Created on 11/04/2011

@author: acalvo
'''
from rdflib import Graph,Namespace

FOAF = Namespace("http://xmlns.com/foaf/0.1/")
RDFS = Namespace("http://www.w3.org/2000/01/rdf-schema#")

my_data ='''
                @prefix org:    <http://example.com/ns#> .

                _:a  org:employeeName   "Alice" .
                _:a  org:employeeId     12345 .
                
                _:b  org:employeeName   "Bob" .
                _:b  org:employeeId     67890 .


     '''
g = Graph()
g.parse(data=my_data, format="n3")
    #print 'result',result
    #print len(g)
print g.serialize(format='xml')
    #print g.serialize(format='n3')


#2.5 Building RDF Graphs
def q1():
          
    query='''    
            PREFIX foaf:   <http://xmlns.com/foaf/0.1/>
            PREFIX org:    <http://example.com/ns#>
            
            CONSTRUCT { ?x foaf:name ?name }
            WHERE  { ?x org:employeeName ?name } 



''' 
    result=g.query(query)
    
    
    print '===================='
    print '===>',result
    print result.serialize()
    print '===================='
    

    for row in result:
        print row
        #print "%s es %s" % tuple(row)
        
if __name__ == '__main__':

    if True:
        q1()

        
        
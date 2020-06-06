#! /usr/bin/python
# makeTriples.py: demonstrate the creation of an RDFLib TripleStore

from rdflib.sparql.bison import Parse
from rdflib.Literal import Literal
from rdflib.Namespace import Namespace
from rdflib.sparql.sparqlGraph import SPARQLGraph
from rdflib.sparql.graphPattern import *
from rdflib import Graph
 

ns_fich=Namespace('fich="http://siva.uco.es/onto/owl/fichas-01#')

ns_rdf=Namespace("http://www.w3.org/1999/02/22-rdf-syntax-ns#")
ns_xs=Namespace("http://www.w3.org/2001/XMLSchema#")
 
ns_rdfs=Namespace("http://www.w3.org/2000/01/rdf-schema#")
ns_owl=Namespace("http://siva.uco.es/onto/owl/personas-01#")
ns_dam=Namespace("http://www.daml.org/2001/03/daml+oil#")
ns_dc=Namespace("http://purl.org/dc/elements/1.1/")
ns_per=Namespace("http://siva.uco.es/onto/owl/personas-01#")
ns_hechos=Namespace("http://siva.uco.es/onto/owl/hechos-01#")
ns_lug=Namespace("http://siva.uco.es/onto/owl/lugares-01#")
ns_fich=Namespace("http://siva.uco.es/onto/owl/fichas-01#")
ns_idp=Namespace("http://siva.uco.es/onto/owl/identificacion-personajes-01#")



prefijo= '''
        PREFIX fich: <http://siva.uco.es/onto/owl/fichas-01#>
        PREFIX rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns#>
        PREFIX rdfs: <http://www.w3.org/2000/01/rdf-schema/>
        PREFIX xs: <http://www.w3.org/2001/XMLSchema/>
        PREFIX per: <http://siva.uco.es/onto/owl/personas-01#>
        PREFIX dam: <http://www.daml.org/2001/03/daml+oil/>
        PREFIX dc: <http://purl.org/dc/elements/1.1/>
        PREFIX hechos: <http://siva.uco.es/onto/owl/hechos-01#>
        PREFIX lug: <http://siva.uco.es/onto/owl/lugares-01#>
        PREFIX fich: <http://siva.uco.es/onto/owl/fichas-01#>
        PREFIX idp: <http://siva.uco.es/onto/owl/identificacion-personajes-01#>
'''        

store = Graph()
 
 
#store.parse('http://siva.uco.es/onto/owl/personas-01.rdf')
store.parse('identificacion-personajes-01.rdf')
#print store.serialize(format="pretty-xml")
 
def objetos():
        
    #for o in store.objects(subject=ns_per['Mujer'], predicate=None):
    for o in store.objects(subject=None, predicate=None):        
        print "objeto:",o, "\n"
        pass

def sujetos():
    for s in store.subjects(predicate=None,object=None):
        print "sujeto:",s,"\n"
        pass
        #for o in store.objects(subject=s, predicate=None):
        #    print o
        #print '---------------------------------'
        #pass
def predicados():
    for p in store.predicates():
        print p
        pass

def idPersonas():
    print 'idPersonas'
    print 
    for o in store.objects(subject=None, 
                           predicate=ns_per['esposaDe']):
        print "objeto:",o, "\n"
        pass

def clasesPersonas():
    print 'Todas las subclases de la clase Persona '
     
    test_query = """
        PREFIX fich: <http://siva.uco.es/onto/owl/fichas-01#>
        PREFIX rdf: <http://www.w3.org/1999/02/22-rdf-syntax-ns/>
        PREFIX rdfs: <http://www.w3.org/2000/01/rdf-schema/>
        PREFIX xs: <http://www.w3.org/2001/XMLSchema/>
        PREFIX per: <http://siva.uco.es/onto/owl/personas-01#>
        PREFIX dam: <http://www.daml.org/2001/03/daml+oil/>
        PREFIX dc: <http://purl.org/dc/elements/1.1/>
        PREFIX hechos: <http://siva.uco.es/onto/owl/hechos-01#>
        PREFIX lug: <http://siva.uco.es/onto/owl/lugares-01#>
        PREFIX fich: <http://siva.uco.es/onto/owl/fichas-01#>
        PREFIX idp: <http://siva.uco.es/onto/owl/identificacion-personajes-01#>
        
        SELECT ?s 
        WHERE { ?s per:madreDeHija ?o
               }
     """ 
 
    results = store.query(test_query)
    print results.serialize(format='xml')

def clasesPersonas1():
    print 'Todas las subclases de la clase Persona '
     
    test_query = """
        SELECT   ?s ?o
        WHERE { idp:Mujer_Araceli_Serrano_Tenllado per:esposaDe ?o }
     """ 
    test_query = prefijo + test_query 
    results = store.query(test_query)
    print results.serialize(format='xml')


def clasesPersonas2():
    print 'Todas las subclases de la clase Persona '
     
    test_query = """
         
        SELECT  ?s  ?p
        WHERE {?s  ?p    idp:Mujer_Araceli_Serrano_Tenllado }
     """ 
    test_query = prefijo + test_query 

    #print test_query
    results = store.query(test_query)
    print results.serialize(format='xml')


def clasesPersonas3():
    print 'Todas las subclases de la clase Persona '
     
    test_query = """
                SELECT   ?s
        WHERE { ?s rdf:type per:Hombre}
     """ 
    test_query = prefijo + test_query
    
    results = store.query(test_query)
    print results.serialize(format='xml')

         
#idPersonas() 
#sujetos()
#predicados()        
#objetos()
#clasesPersonas2()
clasesPersonas3()

store.close()

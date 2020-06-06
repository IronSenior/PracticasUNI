#! /usr/bin/python


from rdflib import ConjunctiveGraph, Graph
from rdflib import Literal
from rdflib import Namespace
#from rdflib import sparqlGraph

#xmlns:per="http://www.domain2.com#"
#xmlns:rdf="http://www.w3.org/1999/02/22-rdf-syntax-ns#"
#xmlns:xsd="http://www.w3.org/2001/XMLSchema#"
#xmlns:rdfs="http://www.w3.org/2000/01/rdf-schema#"
#xmlns:owl="http://www.w3.org/2002/07/owl#"
#xmlns="http://www.owl-ontologies.com/Ontology1227083014.owl#"
#xml:base="http://www.owl-ontologies.com/Ontology1227083014.owl"             

#Se declaran espacios de nombres
ns_rdf=Namespace("http://www.w3.org/1999/02/22-rdf-syntax-ns#")
ns_xs=Namespace("http://www.w3.org/2001/XMLSchema#")
ns_rdfs=Namespace("http://www.w3.org/2000/01/rdf-schema#")
ns_owl=Namespace("http://www.w3.org/2002/07/owl#")
ns_per=Namespace("http://www.owl-ontologies.com/Ontology1227083014.owl#")
 
store = Graph()#Se crea una instancia de la clase Graph

#store.parse('identificacion-personajes.rdf')
store.parse('personas.owl') #Rellena el grafo con el fichero personas.owl
print store.serialize()
 
def objetos():
        
    #for o in store.objects(subject=ns_per['Hombre'], predicate=ns_rdfs['subClassOf']):
    for o in store.objects(subject=None, predicate=ns_per['residencias']):
    #for o in store.objects(subject=None, predicate=ns_rdfs['subClassOf']):
    #for o in store.objects(subject=None, predicate=None):        
        print "objeto:",o, "\n"
        pass
    print '..................'
    #for o in store.objects(subject=ns_per['Hombre_Calvo_Serrano'], predicate=ns_per['nombre']):
    #for o in store.objects(subject=ns_per['Hombre_Calvo_Serrano'], predicate=None):
    #for o in store.objects(subject=None, predicate=None):        
    #        print "objeto:",o, "\n"
    #        pass


    

def sujetos():
    #for s in store.subjects(ns_per['nombre'], Literal("Antonio")):#no funciona
    #for s in store.subjects(ns_per['nombre'], Literal("Antonio",datatype="http://www.w3.org/2001/XMLSchema#string")):#si funciona
    for s in store.subjects(predicate=ns_per['nombre'],object=None):
    #for s in store.subjects(ns_per['residencias'], Literal("Lucena",language="es")):#no funciona        
    #for s in store.subjects(predicate=None,object=None):
        print "sujeto:",s,"\n"
        pass
        #for o in store.objects(subject=s, predicate=ns_per['nombre']):
        #    print o
        #print '---------------------------------'
        #pass
def predicados():
    #for p in store.predicates():
    for p in store.predicates(subject=ns_per['Hombre_Calvo_Serrano'], object=None):
        print p
        pass

def idPersonas():
    for o in store.objects(subject=ns_per['Hombre_Calvo_Serrano'], predicate=None):
        print "objeto:",o
        pass


if __name__ == '__main__':

    objetos()
    sujetos()
    predicados()
    #idPersonas() 

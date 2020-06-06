#! /usr/bin/python
#
from rdflib import ConjunctiveGraph, Graph
from rdflib  import Literal
from rdflib  import Namespace
from rdflib  import BNode


# Declara nombres de espacios de nombres para usarlos
ns_per = Namespace("http://siva.uco.es/onto/personas-01#")
 

#store = ConjunctiveGraph()
store =  Graph() #Crea un grafo
store.bind('per',ns_per) #Asocia un prefijo a un espacio de nombres
 
# Aade tripletas al almacen 
store.add((ns_per["d1001"], ns_per["nombre"], Literal("Antonio")))
store.add((ns_per["d1001"], ns_per["apellidos"], Literal("Calvo Cuenca")))
store.add((ns_per["d1001"], ns_per["residencia"], Literal("Cordoba")))
store.add((ns_per["d1001"], ns_per["lugarNacimiento"], Literal("Lucena")))

store.add((ns_per["d1002"], ns_per["nombre"], Literal("Manuel")))
store.add((ns_per["d1002"], ns_per["apellidos"], Literal("Calvo Cuenca")))
store.add((ns_per["d1002"], ns_per["residencia"], Literal("Cordoba")))
store.add((ns_per["d1002"], ns_per["lugarNacimiento"], Literal("Lucena")))

b= BNode()#Crea un nodo blanco
store.add((ns_per["d1003"], ns_per["lugarNacimiento"], b))

store.commit()
print 'Nmero de tripletas:', len(store),"\n"
print 'Presentacin xml'
print '============'
print store.serialize(format="xml")
store.serialize(format="xml",destination='grafo-1.xml',encoding='iso-8859-1')
print u'Presentacin n3'
print '============'
store.serialize(format="n3",destination='grafo-1.n3')
print store.serialize(format="n3")

#!/usr/bin/env python
# -*- coding: iso-8859-1 -*-

import unittest

from tempfile import mkdtemp

from rdflib import URIRef, BNode, Literal, RDF
from rdflib.Graph import Graph

class GraphTestCase():
    store_name = 'default'
    path = 'd:/docenc-1/lenguajes-marcados-5-curso/curso-2008-200/rdf-lib'
    #path =None
    slowtest = True

    def setUp(self):
        self.graph = Graph(store=self.store_name)
        a_tmp_dir = mkdtemp()
        print 'imprimiendo a_tmp_dir',  a_tmp_dir
        self.path = self.path or a_tmp_dir
        print 'imprimiendo self.path', self.path
        self.graph.open(self.path)
        print self.graph.serialize()
        self.michel = URIRef(u'michel')
        self.tarek = URIRef(u'tarek')
        self.bob = URIRef(u'bob')
        self.likes = URIRef(u'likes')
        self.hates = URIRef(u'hates')
        self.pizza = URIRef(u'pizza')
        self.cheese = URIRef(u'cheese')
        print 'terminando setuP self.graph'
        print '======================'
        print self.graph.serialize()
    def tearDown(self):
        self.graph.close()
        print  self.graph.serialize()        

    def addStuff(self):
        tarek = self.tarek
        michel = self.michel
        bob = self.bob
        likes = self.likes
        hates = self.hates
        pizza = self.pizza
        cheese = self.cheese

        self.graph.add((tarek, likes, pizza))
        self.graph.add((tarek, likes, cheese))
        self.graph.add((michel, likes, pizza))
        self.graph.add((michel, likes, cheese))
        self.graph.add((bob, likes, cheese))
        self.graph.add((bob, hates, pizza))
        self.graph.add((bob, hates, michel)) # gasp!
        print 'Imprimiendo el grafo',self.graph.triples
        for t in self.graph:
            print 't=',t
        self.graph.serialize(destination='a.rdf',encoding='iso-8859-1')
        print self.graph.serialize(encoding='iso-8859-1')#no funciona
 
    def removeStuff(self):
        tarek = self.tarek
        michel = self.michel
        bob = self.bob
        likes = self.likes
        hates = self.hates
        pizza = self.pizza
        cheese = self.cheese

        self.graph.remove((tarek, likes, pizza))
        self.graph.remove((tarek, likes, cheese))
        self.graph.remove((michel, likes, pizza))
        self.graph.remove((michel, likes, cheese))
        self.graph.remove((bob, likes, cheese))
        self.graph.remove((bob, hates, pizza))
        self.graph.remove((bob, hates, michel)) # gasp!
        print 'Imprimiendo el grafo despu�s de removeStuff', self.graph.triples
        for t in self.graph:
            print 't=',t
        #print   self.graph.serialize()  no funciona
        
    def testAdd(self):
        self.addStuff()

    def testRemove(self):
        self.addStuff()
        self.removeStuff()

    def testTriples(self):
        tarek = self.tarek
        michel = self.michel
        bob = self.bob
        likes = self.likes
        hates = self.hates
        pizza = self.pizza
        cheese = self.cheese
        asserte = self.assertEquals
        triples = self.graph.triples
        Any = None

        self.addStuff()

        # unbound subjects
        asserte(len(list(triples((Any, likes, pizza)))), 2)
        asserte(len(list(triples((Any, hates, pizza)))), 1)
        asserte(len(list(triples((Any, likes, cheese)))), 3)
        asserte(len(list(triples((Any, hates, cheese)))), 0)

        # unbound objects
        asserte(len(list(triples((michel, likes, Any)))), 2)
        asserte(len(list(triples((tarek, likes, Any)))), 2)
        asserte(len(list(triples((bob, hates, Any)))), 2)
        asserte(len(list(triples((bob, likes, Any)))), 1)

        # unbound predicates
        asserte(len(list(triples((michel, Any, cheese)))), 1)
        asserte(len(list(triples((tarek, Any, cheese)))), 1)
        asserte(len(list(triples((bob, Any, pizza)))), 1)
        asserte(len(list(triples((bob, Any, michel)))), 1)

        # unbound subject, objects
        asserte(len(list(triples((Any, hates, Any)))), 2)
        asserte(len(list(triples((Any, likes, Any)))), 5)

        # unbound predicates, objects
        asserte(len(list(triples((michel, Any, Any)))), 2)
        asserte(len(list(triples((bob, Any, Any)))), 3)
        asserte(len(list(triples((tarek, Any, Any)))), 2)

        # unbound subjects, predicates
        asserte(len(list(triples((Any, Any, pizza)))), 3)
        asserte(len(list(triples((Any, Any, cheese)))), 3)
        asserte(len(list(triples((Any, Any, michel)))), 1)

        # all unbound
        asserte(len(list(triples((Any, Any, Any)))), 7)
        self.removeStuff()
        asserte(len(list(triples((Any, Any, Any)))), 0)


    def testStatementNode(self):
        graph = self.graph

        from rdflib.Statement import Statement
        c = URIRef("http://example.org/foo#c")
        r = URIRef("http://example.org/foo#r")
        s = Statement((self.michel, self.likes, self.pizza), c)
        graph.add((s, RDF.value, r))
        print 'imprimiendo en testStatementNode'
        print '---------------------------------'
        self.graph.serialize(forma='xml')
        for t in self.graph:
            print t
        #self.assertEquals(r, graph.value(s, RDF.value))
        #self.assertEquals(s, graph.value(predicate=RDF.value, object=r))

    def testGraphValue(self):
        from rdflib.Graph import GraphValue

        graph = self.graph

        alice = URIRef("alice")
        bob = URIRef("bob")
        pizza = URIRef("pizza")
        cheese = URIRef("cheese")

        g1 = Graph()
        print g1.n3()

        
        g1.add((alice, RDF.value, pizza))
        g1.add((bob, RDF.value, cheese))
        g1.add((bob, RDF.value, pizza))
        print 'g1.serialize()----------------------------------\n\n'
        print g1.serialize()
        print '\n\n'
        g2 = Graph()
        g2.add((bob, RDF.value, pizza))
        g2.add((bob, RDF.value, cheese))
        g2.add((alice, RDF.value, pizza))

        gv1 = GraphValue(store=graph.store, graph=g1)
        gv2 = GraphValue(store=graph.store, graph=g2)
        print '\n\n gv1.serialize()----------------------------------'
        print gv1.serialize()
        print '\n\n'
        graph.add((gv1, RDF.value, gv2))
        v = graph.value(gv1)
        print 'el tipo de v es: ',type(v)
        print '\n\n v.serialize()----------------------------------'
        print v.serialize()
        print 'fin\n\n'
        
        #self.assertEquals(gv2, v)
        print list(gv2)
        print
        
        print gv2.identifier
        print
        
        print graph.serialize()
        graph.remove((gv1, RDF.value, gv2))

    def testConnected(self):
        graph = self.graph
        self.addStuff()
        self.assertEquals(True, graph.connected())

        jeroen = URIRef("jeroen")
        unconnected = URIRef("unconnected")

        graph.add((jeroen,self.likes,unconnected))

        self.assertEquals(False, graph.connected())

 
g=GraphTestCase()
g.setUp()
#g.tearDown()
#g.testAdd()
#g.removeStuff()
#g.testStatementNode()
#g.testGraphValue()
print 




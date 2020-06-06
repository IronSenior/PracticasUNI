import logging

# Configure how we want rdflib logger to log messages
_logger = logging.getLogger("rdflib")
_logger.setLevel(logging.DEBUG)
_hdlr = logging.StreamHandler()
_hdlr.setFormatter(logging.Formatter('%(name)s %(levelname)s: %(message)s'))
_logger.addHandler(_hdlr)

from rdflib import Graph
from rdflib import URIRef, Literal, BNode, Namespace
from rdflib import RDF

# Create a namespace object for the Friend of a friend namespace.
FOAF = Namespace("http://xmlns.com/foaf/0.1/")

def inicio():
    store = Graph()

    # Bind a few prefix, namespace pairs.
    store.bind("dc", "http://http://purl.org/dc/elements/1.1/")
    store.bind("foaf", "http://xmlns.com/foaf/0.1/")

    # Create a namespace object for the Friend of a friend namespace.
    FOAF = Namespace("http://xmlns.com/foaf/0.1/")

    # Create an identifier to use as the subject for Donna.
    #donna = BNode()
    donna = URIRef("http://siva.uco.es/Mujer_donna")
    
    man = BNode()
 
 
    # Add triples using store's add method.
    store.add((donna, RDF.type, FOAF["Person"]))
    store.add((donna, FOAF["nick"], Literal("donna", lang="foo")))
    store.add((donna, FOAF["name"], Literal("Donna Fales")))

    store.add((man, RDF.type, FOAF["Person"]))
    store.add((man, FOAF["nick"], Literal("jhony", lang="foo")))
    store.add((man, FOAF["name"], Literal('Jhon Matews')))
    print store.serialize()
    return(store)

def iteraciones(store):

    # Iterate over triples in store and print them out.
    print "--- Imprimiendo tripletes ---"
    for s, p, o in store:
        print s, p, o, '-'

    # For each foaf:Person in the store print out its mbox property.
    print "--- Imprimiendo Nombres ---"
    for person in store.subjects(RDF.type, FOAF["Person"]):
        for name in store.objects(person, FOAF["name"]):
            print name
     
    print '------------------------'
    print


    # For each foaf:Person in the store print out its mbox property.
    print "--- Imprimiendo predicados ---"
    for person in store.subjects(RDF.type, FOAF["Person"]):
        for pre in store.predicates(person, Literal("man", lang="foo")):
            print person, pre
     
    print '------------------------'
    print

    # For each foaf:Person in the store print out its mbox property.
    print "--- printing obj ---"
    for person in store.subjects(RDF.type, FOAF["Person"]):
        for obj in store.subjects(Literal("man", lang="foo")):
            print person, obj
     
    print '------------------------'
    print


def serializar(store):

    # Serialize the store as RDF/XML to the file foaf.rdf.
    store.serialize("foaf.rdf", format="pretty-xml", max_depth=3)

    # Let's show off the serializers

    print "RDF Serializations:"

    # Serialize as XML
    print "--- start: rdf-xml ---"
    print store.serialize(format="pretty-xml")
    print "--- end: rdf-xml ---\n"

    # Serialize as NTriples
    print "--- start: ntriples ---"
    print store.serialize(format="nt")
    print "--- end: ntriples ---\n"


if __name__ == '__main__':

    store=inicio()
    iteraciones(store)
    serializar(store)


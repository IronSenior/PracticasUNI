# cribbed from
#  http://rdflib.net/stable/example.py

from rdflib import ConjunctiveGraph, Graph
from rdflib import Namespace
from rdflib import Literal

FOAF = Namespace("http://xmlns.com/foaf/0.1/")
EX = Namespace("http://example.org/foovocab#")

def main():
    s = Graph()
    s.parse("exe2.rdf")
    print s.serialize()

    # find a guy named bob...
    print 'Encuentra un indiciduo llamado Bob...'
    for who in s.subjects(FOAF["name"], Literal("Bob")):
        bob = who
        print  who
        
    print '==============================='
    # who is secretlyStalking bob?
    print '  Quien es la secretaria de  bob?'
    
    for who in s.subjects(EX["secretlyStalking"], bob):
        for n in s.objects(who, FOAF["name"]):
            print n, "is secretlyStalking Bob!"

if __name__ == '__main__':
    main()

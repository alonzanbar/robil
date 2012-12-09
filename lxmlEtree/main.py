# -*- coding: utf-8 -*-
"""

@author: polak
"""
from tree import xmlTree
from Node import node

import sys

def main(argv):
    #create the tree parser. recive filename
    tree = xmlTree(argv)
    #get root from the tree
    root = tree.getRoot()
    #get child at place 0 in the child-list
    child = root.getChild(0)
    #set new attribute to child, time="12"
    child.setAttrib("time", "12")
    #write the tree back to xml file- OUT.xml
    tree.treeToXml("OUT.xml")
    

def mainFromScrath():
    #create the tree root
    tree = node()
    #create a new seq child
    child = tree.addNode("seq")
    #add attribute to the new node
    child.setAttrib("probability", "{(0.5), (0.2),(0.1),(0.9)})")
    #write the tree to xml file    
    tree.treeToXml("OUT2.xml")
    

if __name__ == "__main__":
    #, sys.argv[0] is the name of the script
    #, sys.argv[1] is the type of work- from scrath=1 or from an XML file=2
    # sys.argv[2] is the xml file name
    if sys.argv[1:] == 1:
        mainFromScrath()
    else:
        main(sys.argv[2])
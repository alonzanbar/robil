# -*- coding: utf-8 -*-
"""

@author: polak
"""

from Node import node

class monitorNode (node):
    def __init__(self,treeInst,mytree):
        node.__init__(self,treeInst,mytree,"monitor")
    
    def run (self):
        print ("please implemnt run func in monitorNode")
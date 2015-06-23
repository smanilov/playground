#! /usr/bin/python
import sys

if len(sys.argv) < 2:
    print "Pass filename as argument"
    sys.exit(0)

text = open(sys.argv[1]).read()

scopes = {
        0: "global",
        1: "function",
        2: "higher"
        }

scope = 0

stms = []

def istype(word):
    return word == "int"

def startfun(funname):
    print "   ", len(stms), "[label=" + funname + " shape=box];"
    stms.append(funname)

def endfun(funname):
    None

def addstatement(statement):
    curstm = len(stms)
    stms.append(statement)

    print "   ", curstm, '[label="" shape=circle width=0.20]'

    if curstm > 0:
        print "   ", (curstm-1), "->", curstm

print "digraph {"

statement = False
linecount = 0
funname = ""
for line in text.split('\n'):
    linecount += 1
    # if the line ends in a semicolon then it's a statment
    if line.endswith(';'):
        statement = True
    else:
        statement = False

    tokens = line.split(' ')
    for token in tokens: 
        if '{' in token:
            scope += 1
        if '}' in token:
            scope -= 1
            if scope == 0:
                endfun(funname)
    
    if statement:
        addstatement(line)
    else:
        # then perhaps function definition
        if istype(tokens[0]):
            idx = tokens[1].find('(')
            funname = tokens[1][0:idx]
            startfun(funname)

print "}"

#!/usr/bin/python

import sys

LONG_PARAGRAPH_THRESH = 400
LONG_START_LEN = 197
LONG_END_LEN = 197

if len(sys.argv) < 2:
        print 'Give me a text file as an argument.'
        sys.exit(0)

f = open(sys.argv[1])   # open file
t = f.read()            # read text
ps = t.split('\n\n')    # get paragraphs

ps_ = []                # shortened paragraphs go here

for p in ps:
        if len(p) < LONG_PARAGRAPH_THRESH:
                ps_.append(p)
                continue
        ss = p.split('. ')      # get sentences
        ss_ = []                # short paragraph sentences go here
        totlen = 0              # total length of accepted sentences
        for s in ss:
                if totlen + len(s) > LONG_START_LEN:
                        ss_.append(s[:LONG_START_LEN - totlen] + "..")
                        break;
                ss_.append(s)
                totlen += len(s)
        index = len(ss_)        # index to insert end sentences

        totlen = 0
        ss.reverse()
        for s in ss:
                if totlen + len(s) > LONG_END_LEN:
                        ss_.insert(index, "..." + s[len(s) - (LONG_END_LEN - totlen):])
                        break;
                ss_.insert(index, s)
                totlen += len(s)
        p_ = '. '.join(ss_)
        ps_.append(p_)

t_ = '\n\n'.join(ps_)
print t_

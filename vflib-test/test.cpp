#include <iostream>

using std::cout;

#include "argraph.h"
#include "argedit.h"
#include "vf2_sub_state.h"
#include "match.h"

#define MAXNODES 200

class Operation {
public:
        virtual bool equals(const Operation& other) const = 0;
        bool operator==(const Operation& other) {
                return equals(other);
        }
};


class SingleOperation : public Operation {
public:
        virtual bool equals(const Operation& other) const override {
                return NULL != dynamic_cast<const SingleOperation*>(&other);
        }
};

class OperationAddition : public SingleOperation {
public:
        virtual bool equals(const Operation& other) const override {
                return NULL != dynamic_cast<const OperationAddition*>(&other);
        }
};

class OperationSource : public SingleOperation {
public:
        virtual bool equals(const Operation& other) const override {
                return NULL != dynamic_cast<const OperationSource*>(&other);
        }
};


class CompositeOperation : public Operation {
public:
        virtual bool equals(const Operation& other) const override {
                const CompositeOperation* other_ptr = 
                        dynamic_cast<const CompositeOperation*>(&other);
                return other_ptr != NULL;
        }
};

class ParallelOperation : public CompositeOperation {
public:
        virtual bool equals(const Operation& other) const override {
                return NULL != dynamic_cast<const ParallelOperation*>(&other);
        }
};

class SerialOperation : public CompositeOperation {
public:
        virtual bool equals(const Operation& other) const override {
                return NULL != dynamic_cast<const SerialOperation*>(&other);
        }
};


class Relation {
};

class RelationContains : public Relation {
};

class RelationPrecedes : public Relation {
};


class Destroyer : public AttrDestroyer {
public:
        virtual void destroy(void *p) {
                delete static_cast<Operation*>(p);
        }

};


class EqualityComparator: public AttrComparator {
public:
        virtual bool compatible(void *pa, void *pb) {
                cout << "comparing " << pa << " and " << pb << '\n';
                Operation* a = static_cast<Operation*>(pa);
                Operation* b = static_cast<Operation*>(pb);

                return *a == *b;
        }
};


int main() {
        // Build K4
        ARGEdit editor_k4;  // The object used to create the graph

        editor_k4.InsertNode(new SerialOperation());
        editor_k4.InsertNode(new ParallelOperation());
        editor_k4.InsertNode(new OperationSource());
        editor_k4.InsertNode(new OperationSource());
        editor_k4.InsertNode(new OperationAddition());

        RelationContains* contains = new RelationContains();
        RelationPrecedes* precedes = new RelationPrecedes();

        editor_k4.InsertEdge(0, 1, contains);
        editor_k4.InsertEdge(0, 4, contains);
        editor_k4.InsertEdge(1, 2, contains);
        editor_k4.InsertEdge(1, 3, contains);
        editor_k4.InsertEdge(1, 4, precedes);

        ARGraph<Operation, Relation> k4(&editor_k4);


        ARGEdit editor_k3;  // The object used to create the graph

        editor_k3.InsertNode(new SerialOperation());
        editor_k3.InsertNode(new ParallelOperation());
        editor_k3.InsertNode(new OperationSource());
        editor_k3.InsertNode(new OperationSource());
        editor_k3.InsertNode(new OperationAddition());

        editor_k3.InsertEdge(0, 1, contains);
        editor_k3.InsertEdge(0, 4, contains);
        editor_k3.InsertEdge(1, 2, contains);
        editor_k3.InsertEdge(1, 3, contains);
        editor_k3.InsertEdge(1, 4, precedes);

        ARGraph<Operation, Relation> k3(&editor_k3);

        k4.SetNodeDestroyer(new Destroyer());
        k3.SetNodeDestroyer(new Destroyer());

        k3.SetNodeComparator(new EqualityComparator());

        // Create the initial state of the search space
        VF2SubState s0(&k3, &k4);

        int n;
        node_id ni1[MAXNODES], ni2[MAXNODES];

        if (!match(&s0, &n, ni1, ni2)) {
                cout << "No matching found\n";
                return 1;
        }

        cout << "Found a matching with " << n << " nodes\n";

        for (int i = 0; i < n; ++i) {
                cout << "\tNode " << ni1[i] << " of graph1 is paired with"
                        " node " << ni2[i] << " of graph2\n";

        }

        return 0;
}

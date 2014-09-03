#ifndef TRAVERSAL
#define TRAVERSAL

#include <vector>
#include <iostream>

using std::vector;
using std::cout;

struct direction {
        char val;

        /// Flip: up <-> down; right <-> left.
        direction flip() {
                direction ret;
                switch (val) {
                        case 'u': ret = {'d'}; break;
                        case 'd': ret = {'u'}; break;
                        case 'l': ret = {'r'}; break;
                        case 'r': ret = {'l'}; break;
                }
                return ret;
        }

        /// Rotate in the positive direction (ccw)
        direction rotp() {
                direction ret;
                switch (val) {
                        case 'u': ret = {'l'}; break;
                        case 'l': ret = {'d'}; break;
                        case 'd': ret = {'r'}; break;
                        case 'r': ret = {'u'}; break;
                }
                return ret;
        }

        /// Rotate in the negative direction (cw)
        direction rotn() {
                direction ret;
                switch (val) {
                        case 'u': ret = {'r'}; break;
                        case 'r': ret = {'d'}; break;
                        case 'd': ret = {'l'}; break;
                        case 'l': ret = {'u'}; break;
                }
                return ret;
        }
};

struct traversal {
        vector<direction> dirs;

        /// Default constructor: create the empty traversal
        traversal() { }

        /// Create a traversal that describes the same figure, but traversed
        /// from the opposite direction
        traversal reverse() {
                traversal ret;
                for (auto it = dirs.rbegin(); it != dirs.rend(); ++it) {
                        ret.dirs.push_back(it->flip());
                }
                return ret;
        }

        /// Create a traversal that descrives the same figure, but rotated 90
        /// degrees in the positive direction (counter-clockwise)
        traversal rotate_pos() {
                traversal ret;
                for (auto& d : dirs) {
                        ret.dirs.push_back(d.rotp());
                }
                return ret;
        }

        /// Create a traversal that descrives the same figure, but rotated 90
        /// degrees in the negative direction (clockwise)
        traversal rotate_neg() {
                traversal ret;
                for (auto& d : dirs) {
                        ret.dirs.push_back(d.rotn());
                }
                return ret;
        }

        /// Create the next hilbert curve traversal
        traversal next() {
                traversal ret;
                traversal rev = reverse();
                traversal first = rev.rotate_neg();
                traversal last = rev.rotate_pos();
                ret.dirs.insert(ret.dirs.end(), first.dirs.begin(), first.dirs.end());
                ret.dirs.push_back({'u'});
                ret.dirs.insert(ret.dirs.end(), dirs.begin(), dirs.end());
                ret.dirs.push_back({'r'});
                ret.dirs.insert(ret.dirs.end(), dirs.begin(), dirs.end());
                ret.dirs.push_back({'d'});
                ret.dirs.insert(ret.dirs.end(), last.dirs.begin(), last.dirs.end());
                return ret;
        }

        void print() {
                for (auto& d : dirs) {
                        cout << d.val << ' ';
                }
                cout << '\n';
        }
};

#endif

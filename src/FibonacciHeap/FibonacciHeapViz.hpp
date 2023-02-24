#ifndef FIBONACCI_HEAP_VIZ_HPP
#define FIBONACCI_HEAP_VIZ_HPP

#include <list>
#include "FibonacciHeap.hpp"

template<class T>
class FibonacciHeapViz : public FibonacciHeap<T> {
private:
    void _exportDotNode(std::ostream &out, Element<T> *x) {
        if (x == nullptr) return;

        if (x->isMarked()) {
            out << x->getKey() << "[fillcolor=grey, style=filled]" << std::endl;
        }

        out << x->getKey() << "[label=\"" << x->getKey() << " (" << x->getDegree() << ")\"]" << std::endl;

        out << x->getKey() << " -> " << x->getLeft()->getKey() << "[color=red]" << std::endl;
        out << x->getKey() << " -> " << x->getRight()->getKey() << "[color=blue]" << std::endl;

        if (x->getParent() != nullptr) {
            out << x->getKey() << " -> " << x->getParent()->getKey() << "[color=green]" << std::endl;
        }
    }

    void _exportDot(std::ostream &out, Element<T> *x, Element<T> *stop = nullptr, std::list<T> level = std::list<T>()) {
        if (x == nullptr) return;

        if (stop != nullptr && x == stop) {
            out << "{rank=same;";
            for (const auto &n : level) {
                out << " " << n;
            }
            out << ";}" << std::endl;

            return;
        }

        this->_exportDotNode(out, x);

        if (x->getChild() != nullptr) {
            out << x->getKey() << " -> " << x->getChild()->getKey() << "[color=black]" << std::endl;
            this->_exportDot(out, x->getChild());
        }

        if (stop == nullptr) {
            stop = x;
        }

        level.push_back(x->getKey());
        this->_exportDot(out, x->getRight(), stop, level);
    }

public:
    void exportDOT(std::ostream &out = std::cout) {
        out << "digraph G {" << std::endl;
        if (this->min == nullptr) {
            out << "}" << std::endl;
            return;
        }

        out << "min -> " << this->min->getKey() << std::endl;

        this->_exportDot(out, this->min);

        out << "}" << std::endl;
    }
};

#endif // FIBONACCI_HEAP_VIZ_HPP

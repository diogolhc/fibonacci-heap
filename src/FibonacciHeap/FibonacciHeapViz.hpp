#ifndef FIBONACCI_HEAP_VIZ_HPP
#define FIBONACCI_HEAP_VIZ_HPP

#include <list>
#include <iostream>
#include "FibonacciHeap.hpp"

template<class T>
class FibonacciHeapViz : public FibonacciHeap<T> {
private:
    std::size_t _id(Element<T> *x) {
        return std::hash<Element<T>*>{}(x);
    }

    void _exportDotNode(std::ostream &out, Element<T> *x) {
        if (x == nullptr) return;

        if (x->isMarked()) {
            out << _id(x) << "[fillcolor=grey, style=filled]" << std::endl;
        }
        
        out << _id(x) << "[label=\"" << x->getKey() << " (" << x->getDegree() << ")\"]" << std::endl;

        out << _id(x) << " -> " << _id(x->getLeft()) << "[color=red]" << std::endl;
        out << _id(x) << " -> " << _id(x->getRight()) << "[color=blue]" << std::endl;

        if (x->getParent() != nullptr) {
            out << _id(x) << " -> " << _id(x->getParent()) << "[color=green]" << std::endl;
        }
    }

    void _exportDot(std::ostream &out, Element<T> *x, Element<T> *stop = nullptr, std::list<std::size_t> level = std::list<std::size_t>()) {
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
            out << _id(x) << " -> " << _id(x->getChild()) << "[color=black]" << std::endl;
            this->_exportDot(out, x->getChild());
        }

        if (stop == nullptr) {
            stop = x;
        }

        level.push_back(_id(x));
        this->_exportDot(out, x->getRight(), stop, level);
    }

public:
    void exportDOT(std::ostream &out = std::cout) {
        out << "digraph G {" << std::endl;
        if (this->min == nullptr) {
            out << "}" << std::endl;
            return;
        }

        out << "min -> " << _id(this->min) << std::endl;

        this->_exportDot(out, this->min);

        out << "}" << std::endl;
    }
};

#endif // FIBONACCI_HEAP_VIZ_HPP

#ifndef NODE_H_
#define NODE_H_

/***** Convert this to a class template to handle
 ***** multiple types of data stored in the nodes. */

using namespace std;

template<typename T1>
class Node
{
public:
    Node<T1>(T1 value);
    ~Node();

    T1 data;
    Node<T1> *next;
};

template<typename T1>
Node<T1>::Node(T1 value) : data(value), next(nullptr)
{
}

template<typename T1>
Node<T1>::~Node()
{
}

#endif /* NODE_H_ */

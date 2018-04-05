//
//  rootnode.hpp
//  borgfs
//
//  Created by Paul Ciarlo on 3/21/18.
//  Copyright © 2018 Paul Ciarlo. All rights reserved.
//

#ifndef rootnode_hpp
#define rootnode_hpp

#include "node.hpp"

namespace com {
namespace github {
namespace paulyc {
namespace borgfs {

template <typename Hash_T>
class RootNode : public AbstractNode<Hash_T> {
public:
    RootNode() : AbstractNode<Hash_T>("ROOT") {}
    
    typedef typename AbstractNode<Hash_T>::template generic_node_exception<"This is a root node, can't have ommers\n"> root_node_exception;

protected:
    virtual AbstractNode<Hash_T> &addOmmer(std::shared_ptr<AbstractNode<Hash_T>> ommer) throw(root_node_exception) {
        // this is a root, can't have ommers
        throw root_node_exception();
        return *this;
    }
    
};
    
}
}
}
}

#include "rootnode.cpp"

#endif /* rootnode_hpp */

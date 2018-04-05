//
//  datanode.hpp
//  borgfs
//
//  Created by Paul Ciarlo on 3/21/18.
//  Copyright © 2018 Paul Ciarlo. All rights reserved.
//

#ifndef datanode_hpp
#define datanode_hpp

#include "node.hpp"

namespace com {
namespace github {
namespace paulyc {
namespace borgfs {

template <typename Hash_T>
class DataNode : public AbstractNode<Hash_T> {
public:
    DataNode(const std::string &name, std::unique_ptr<binary_string> data) :
        AbstractNode<Hash_T>(name) {
        _data.swap(data);
        _hash = Hash_T::calculate(data->data(), data->size());
    }
    
    //typedef typename AbstractNode<Hash_T>::node_exception node_exception;
    typedef typename AbstractNode<Hash_T>::template generic_node_exception<"This is a data (leaf) node, can't have children\n"> leaf_node_exception;
    
protected:
    virtual Hash_T getNodeHash() const { return _hash; }
    
    virtual AbstractNode<Hash_T> &addChild(std::shared_ptr<AbstractNode<Hash_T>> child) throw(leaf_node_exception) {
        throw leaf_node_exception();
        return *this;
    }
    
private:
    std::unique_ptr<binary_string> _data;
    typename Hash_T::Output_T _hash;
};
    
}
}
}
}

#include "datanode.cpp"

#endif /* datanode_hpp */

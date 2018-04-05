//
//  subtreenode.hpp
//  borgfs
//
//  Created by Paul Ciarlo on 3/21/18.
//  Copyright © 2018 Paul Ciarlo. All rights reserved.
//

#ifndef subtreenode_hpp
#define subtreenode_hpp

#include "node.hpp"

namespace com {
namespace github {
namespace paulyc {
namespace borgfs {

template <typename Hash_T>
class SubtreeNode : public AbstractNode<Hash_T> {
};
    
}
}
}
}

#include "subtreenode.cpp"

#endif /* subtreenode_hpp */

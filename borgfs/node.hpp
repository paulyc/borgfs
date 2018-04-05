//
//  node.hpp
//  borgfs
//
//  Created by Paul Ciarlo on 3/21/18.
//  Copyright © 2018 Paul Ciarlo. All rights reserved.
//

#ifndef node_hpp
#define node_hpp

#include <sha512-256-impl.h>

#include <list>

namespace com {
namespace github {
namespace paulyc {
namespace borgfs {

typedef sw::detail::binary_string binary_string;

template <typename Hash_T=sw::sha512_256>
class AbstractNode {
public:
    AbstractNode() : _name("defaultName") {}
    AbstractNode(std::string name) : _name(name) {}
    
    virtual ~AbstractNode() {}
    
    std::string getName() const { return _name; }
    //virtual std::string getPath() const = 0;
    
    //typedef std::vector<std::shared_ptr<AbstractNode>> path_struct;
    //virtual path_struct getPathToRoot() = 0;
    //virtual path_struct getShortestPathToRoot() = 0;
    //virtual std::vector<path_struct> getAllPathsToRoot() = 0;
    
    //typedef sw::sha512_256::str_t hash_t;
    
    //const hash_t getHash() const { return *_cachedHash; }
    //const hash_t getSubtreeHash() const { return *_cachedSubtreeHash; }
    
    //class commit_exception : public std::exception {};
    
    //virtual void commit() throw(commit_exception) = 0;
    
    struct node_exception : std::exception {
        node_exception(const char *msg) : _msg(msg) {}
        node_exception(const node_exception &except) : _msg(except._msg) {}
        const char* what() const noexcept { return _msg; }
        const char *_msg;
    };
    
    template <const char *msg>
    struct generic_node_exception : node_exception {
        generic_node_exception() : node_exception(msg) {}
    };
    
protected:
    virtual Hash_T getNodeHash() const = 0;
    virtual Hash_T getSubtreeHash() const { return Hash_T::Output_T(); };
    virtual Hash_T getOmmersHash() const { return Hash_T::Output_T(); };
    
    virtual AbstractNode<Hash_T> &addChild(std::shared_ptr<AbstractNode<Hash_T>> child) throw(node_exception) {
        _childNodes.push_back(child);
        return *this;
    }
    
    virtual AbstractNode<Hash_T> &addOmmer(std::shared_ptr<AbstractNode<Hash_T>> ommer) throw(node_exception) {
        _ommerNodes.push_back(ommer);
        return *this;
    }
    
    //std::map<Hash_T, std::shared_ptr<AbstractNode>> _ommerNodes;
    std::list<std::shared_ptr<AbstractNode>> _ommerNodes;
    std::list<std::shared_ptr<AbstractNode>> _childNodes;
    std::list<std::shared_ptr<AbstractNode>> _siblingNodes;
    
    // just for reference, not included in hash calculaton
    //std::map<Hash_T, std::shared_ptr<AbstractNode>> _childNodes;
    
private:
    std::string _name;
    
};
    
}
}
}
}

#include "node.cpp"

#endif /* node_hpp */

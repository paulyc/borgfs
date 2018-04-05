//
//  localfilestorage.hpp
//  borgfs
//
//  Created by Paul Ciarlo on 3/21/18.
//  Copyright © 2018 Paul Ciarlo. All rights reserved.
//

#ifndef localfilestorage_hpp
#define localfilestorage_hpp

#include "storage.hpp"

namespace com {
namespace github {
namespace paulyc {
namespace borgfs {
    
class LocalFileStorageBackend : public AbstractStorageBackend {
public:
    virtual std::string getName() const { return std::string("LocalFile"); }
};

}
}
}
}

#include "localfilestorage.cpp"

#endif /* localfilestorage_hpp */

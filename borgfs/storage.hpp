//
//  storage.hpp
//  borgfs
//
//  Created by Paul Ciarlo on 3/21/18.
//  Copyright © 2018 Paul Ciarlo. All rights reserved.
//

#ifndef storage_hpp
#define storage_hpp

#include <string>

namespace com {
namespace github {
namespace paulyc {
namespace borgfs {
    
class AbstractStorageBackend {
public:
    virtual std::string getName() const = 0;
};

}
}
}
}

#include "storage.cpp"

#endif /* storage_hpp */

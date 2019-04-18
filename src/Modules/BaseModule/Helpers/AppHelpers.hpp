//
//  AppHelpers.h
//  orange
//
//  Created by Daniel Almeida on 12/04/2019.
//

#ifndef AppHelpers_h
#define AppHelpers_h

namespace Orange {
    namespace Base {
        
        class AppHelpers {
        public:
            static std::string hashString(std::string value) {
                std::hash<std::string> hash_function;
                size_t str_hash = hash_function(value);
                
                return ofToString(str_hash);
            };
        };
    };
};
#endif /* AppHelpers_h */

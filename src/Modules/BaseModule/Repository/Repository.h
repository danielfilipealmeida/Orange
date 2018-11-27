//
//  Repository.h
//  orange
//
//  Created by Daniel Almeida on 21/11/2018.
//

#ifndef Repository_h
#define Repository_h

namespace Orange {
    namespace Base {
        
        /*!
         Repository Template for implementing the Repository Pattern
         using a vector as the data storage.
        
        */
        template <class T>
        class Repository {
            std::vector<T> entities;
            
        public:
            
            /*!
             Get the number of stored entities
             \return int The number of entities
             */
            unsigned int count() {
                return entities.size();
            }
            
            /*!
             Get an entity at a given index
             \return T The requested entity
             */
            T getAt(unsigned int index) {
                return entities[index];
            }
            
            /*!
             Adds an entity at the end of the Repository
             \param T The entity to store
             */
            void add(T entity) {
                entities.push_back(entity);
            }
        };
        
    }
    
}


#endif /* Repository_h */

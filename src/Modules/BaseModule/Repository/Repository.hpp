//
//  Repository.h
//  orange
//
//  Created by Daniel Almeida on 21/11/2018.
//

#ifndef Repository_h
#define Repository_h

#include "ofMain.h"
#include <vector>
#include <functional>

namespace Orange {
    namespace Base {
        
        /*!
         \brief Repository Template for implementing the Repository Pattern using a vector as the data storage.
        
        */
        template <class T>
        class Repository {
            std::vector<T> entities;
            
        public:
            
            
            /*!
             \brief Get the number of stored entities
             \return int The number of entities
             */
            unsigned int count() {
                return entities.size();
            }
            
            /*!
             \brief Get an entity at a given index
             \return T The requested entity
             */
            T getAt(unsigned int index) {
                if (index >= entities.size()) return nullptr;
                return entities[index];
            }
            
            T &operator[](unsigned int index) {
                return entities[index];
            }
            
            /*!
             \brief Adds an entity at the end of the Repository
             \param T The entity to store
             */
            void add(T entity) {
                entities.push_back(entity);
            }
            
            /*!
             \brief Removes an entity in the Repository
             \param unsigned int the position to remove. starts at 0.
             */
            void remove(unsigned int position) {
                entities.erase(entities.begin() + position);
            }
            
            
            /*!
             \brief Traverse all stored entities and to each, run a lambda function with the entity as input
             \param std::function<void (T)> the lambda
             */
            void forEach(std::function<void (T)> lambda) {
                for(T entity:entities) {
                    lambda(entity);
                }
            }
            
            /*!
             Returns the Layer information in JSON format.
             \returns ofJson
             */
            ofJson toJson() {
                ofJson json;
                
                for(T entity:entities) {
                    json.push_back(entity->toJson());
                }
                
                return json;
            }
            
            /*!
             Returns true if the repository is empty
             \return boll
             */
            bool empty() {
                return entities.empty();
            }
            
            /*!
             Releases all entities in repository
             */
            void clear() {
                /*
                for(T entity:entities) {
                    delete entity;
                }
                 */
                entities.clear();
            }
        };
        
        
    }
    
}


#endif /* Repository_h */

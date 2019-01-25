//
//  ofxPaginatedInterface.h
//  orange
//
//  Created by Daniel Almeida on 23/01/2019.
//

#ifndef ofxPaginatedInterface_h
#define ofxPaginatedInterface_h

class ofxPaginatedInterface {
public:
    virtual void setNumberOfPages(unsigned int _numberOfPages) = 0;
    virtual unsigned int getNumberOfPages() = 0;
    virtual void setPage(unsigned int _page) = 0;
    virtual unsigned int getPage() = 0;
};

#endif /* ofxPaginatedInterface_h */

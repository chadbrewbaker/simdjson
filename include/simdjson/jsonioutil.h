#ifndef JSONIOUTIL_H
#define JSONIOUTIL_H

#include <exception>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <string_view>
#include "simdjson/common_defs.h"


// low-level function
// if you must provide a pointer to some data, create it with this function:
// length is the max. size in bytes of the string
// caller is responsible to free the memory (free(...))
char * allocate_aligned_buffer(size_t length);





// load a file in memory...
// get a corpus; pad out to cache line so we can always use SIMD
// throws exceptions in case of failure
// first element of the pair is a string (null terminated)
// whereas the second element is the length.
// caller is responsible to free (free std::pair<u8 *, size_t>.first)
// 
// throws an exception if the file cannot be opened, use try/catch
//      try {
//        p = get_corpus(filename);
//      } catch (const std::exception& e) { 
//        std::cout << "Could not load the file " << filename << std::endl;
//      }
std::string_view  get_corpus(std::string filename);


#endif

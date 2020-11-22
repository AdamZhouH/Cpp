// fig18_06.cpp

// 1. class exceptionType {};
//    try {
//	      throw new exceptionType();    // you can not return a pointer of local objects
//    } catch (exception *pet) {  //TUDO }

// 2. try {
//		  // throw any type of exception would be ok
//    } catch(...) { //TUDO  }

// 3. typedef int EXCPTYPE
//    try {
//		  // throw a int-type data is ok
//    } catch(EXCPTYPE) {  //TUDO }
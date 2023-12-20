/*
 * yri-db-runtime-verif-definition-oo-class-operators.hpp
 *
 *      Author: DR.-ING. DIPL.-INF. XAVIER NOUNDOU
 */

#ifndef _YERITH_ERP_3_0_DEFINITION_OO_CLASS_OPERATORS_HPP_
#define _YERITH_ERP_3_0_DEFINITION_OO_CLASS_OPERATORS_HPP_


#include <cstdlib>


#define YERITH_CLASS_OPERATORS  \
    inline void *operator new[](size_t size){ return calloc(1, size); } \
    inline void *operator new(size_t size){ return calloc(1, size); } \
    inline void operator delete[](void *ptr){ free(ptr); } \
    inline void operator delete[](void *ptr, size_t){ free(ptr); } \
    inline void operator delete(void *ptr){ free(ptr); } \
    inline void operator delete(void *ptr, size_t){ free(ptr); }
#endif //_YERITH_ERP_3_0_DEFINITION_OO_CLASS_OPERATORS_HPP_

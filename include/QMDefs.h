#ifndef QF_DEFS_H
#define QF_DEFS_H

#include <memory>

namespace QuickMath {
enum class QMOpType {LT, LTE, GT, GTE, NE, EQ, BICOND, 
					 IMPL, LAND, LOR, LNOT, BAND, BOR, 
					 BNOT, UKNWN};

template<typename Derived, typename Base>
std::unique_ptr<Derived>
static_uptr_cast(std::unique_ptr<Base> && p) {
    return std::unique_ptr<Derived>(static_cast<Derived*>(p.release()));
}


template<typename Derived, typename Base, typename Del>
std::unique_ptr<Derived, Del>
dynamic_uptr_cast(std::unique_ptr<Base, Del> && p) {
    if(Derived *result = dynamic_cast<Derived *>(p.get()))
    {
        p.release();
        return std::unique_ptr<Derived, Del>(result, p.get_deleter());
    }
    return std::unique_ptr<Derived, Del>(nullptr, p.get_deleter());
}

}




#endif
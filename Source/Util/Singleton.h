#ifndef SINGLETON_H_INCLUDED
#define SINGLETON_H_INCLUDED

#include "NonCopyable.h"
#include "NonMovable.h"

class Singleton : public NonMovable, public NonCopyable {};

template <typename T> class TSingleton : public NonCopyable, public NonMovable {
  public:
    // in golang you can implement such structure using sync.Once
    static T &instance()
    {
        static T s_instance;
        return s_instance;
    }
};

#endif // SINGLETON_H_INCLUDED

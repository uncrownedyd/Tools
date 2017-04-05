#include <unistd.h>
#include <pthread.h>
#include <assert.h>
#include <boost/noncopyable.hpp>

#if 0
#define MCHECK(ret) ({ __type__ (ret) errnum = (ret);       \
                        assert(errnum == 0); (void) errnum;})
#endif

#define DCHECK(ret)                         \
        do { __type__ (ret) errnum = (ret); \   
             assert(errnum == 0); (void) errnum; } while (0)

class MutexLock : boost::noncopyable
{
public:
    MutexLock()
    {
        DCHECK(pthread_mutex_init(&mutex_, NULL));
    }

    ~MutexLock()
    {
        DCHECK(pthread_mutex_destroy(&mutex_));
    }

    void lock()
    {
        DCHECK(pthread_mutex_lock(&mutex_));
    }

    void unlock()
    {
        DCHECK(pthread_mutex_unlock(&mutex_));
    }
    
private:
    pthread_mutex_t mutex_;
};

class MutexLockGuard : boost::noncopyable
{
public:
    explicit MutexLockGuard(MutexLock &mutex) : mutex_(mutex)
    {
        mutex_.lock();
    }

    ~MutexLockGuard()
    {
        mutex_.unlock();
    }

private:
    MutexLock& mutex_;
};

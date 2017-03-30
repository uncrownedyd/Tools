#include <unistd.h>
#include <pthread.h>
#include <boost/noncopyable.hpp>

class MutexLock
{
public:
    MutexLock() : boost::noncopyable
    {
        pthread_mutex_init(&mutex_, NULL);
    }

    ~MutexLock()
    {
        pthread_mutex_destroy(&mutex_);
    }

    void lock()
    {
        pthread_mutex_lock(&mutex_);
    }

    void unlock()
    {
        pthread_mutex_unlock(&mutex_);
    }
    
private:
    pthread_mutex_t mutex_;
};

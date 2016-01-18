#include "mutex.h"

CMutex::CMutex(pthread_mutex_t& m) : m_m(m)
{
}

CMutex::~CMutex()
{
}

void CMutex::Lock()
{
    pthread_mutex_lock(&m_m);
}

void CMutex::UnLock()
{
	if (!(m_m)) return;			// 此值调试时候发现有可能为空，导致程序终止，可能是 lock 与 unlock 不配对 先运行通过
    pthread_mutex_unlock(&m_m);
}

CMutexGuard::CMutexGuard(pthread_mutex_t& m):mm(m)
{
    mm.Lock();
}

CMutexGuard::~CMutexGuard()
{
    mm.UnLock();
}

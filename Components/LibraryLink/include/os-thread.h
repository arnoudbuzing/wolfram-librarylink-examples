/************************************************************************
                        Mathematica source file

        Copyright 1986 through 1999 by Wolfram Research Inc.

This material contains trade secrets and may be registered with the
U.S. Copyright Office as an unpublished work, pursuant to Title 17,
U.S. Code, Section 408.  Unauthorized copying, adaptation, distribution
or display is prohibited.

$Id$

*************************************************************************/

#ifndef OS_THREAD_H
#define OS_THREAD_H

#include "types.h"

#ifdef __cplusplus
extern "C" {
#endif

/* 
 This file contains the exports for the OS independent
 Mathematica Thread API. 

 The implementations are pthreads on Unix and Windows threads 
 on Windows. 
 
 Another difference is in condition variables, Windows does not 
 provide condition variables.  The mechanism is thus emulated on 
 Windows. Thus any use of condition variables on Windows should be
 checked carefully.

 This is not a strict implementation of pthreads
 condition variable behavior on Windows. It is believed, however, that
 the only shortcomings involve fairness when multiple threads are
 waiting on the same condition variable. In the kernel currently there
 are no such cases (cond vars are only ever used by 2 threads, so only
 one is waiting at a time). Here is a good reference on subtleties of
 writing a truly correct implementation of condition vars on Win32:
 http://www.cs.wustl.edu/~schmidt/win32-cv-1.html.
 In particular, our Win32 system is not guaranteed to work well with
 broadcasting signals (waking up all threads waiting instead
 of just a single one). Therefore there is no broadcast function in
 our API.
*/

/*
 KThread objects hold handles to the OS specific implementation 
 of the thread objects.  The thread_handle holds the thread object, 
 nullThread says if the thread handle is null or not.
*/

typedef struct st_KThread
	{
	void* thread_handle;
	}* KThread;

typedef void (*ThreadFunc)(void *);

typedef void* ThreadArg;

#define KTHREAD_PRIORITY_HIGH 1
#define KTHREAD_PRIORITY_NORMAL 2
#define KTHREAD_PRIORITY_LOW 4
#define KTHREAD_DETACHED 8

/*
 Create a thread, starts it running.
*/

KThread KThreadCreate(ThreadFunc, ThreadArg, int);


/*
 Call OS specific functions to terminate a running thread.  KThreadRawExit
 bypasses the KThread module's normal thread shutdown routines.
*/
void KThreadRawExit(void);


/*
 Delete the handle to a thread. Can only be called after the thread has ended.
*/

void Delete_KThread(KThread);

/*
 Make the current thread sleep the specified number of millis.
*/
void KThread_Sleep(int);


/*
 KMutex objects hold handles to the OS specific implementation 
 of mutex objects.
*/

typedef struct st_KMutex
	{
	void* mutex_handle;
	}* KMutex;

KMutex New_KMutex(void);

void Delete_KMutex(KMutex);

void KMutexLock(KMutex);

void KMutexUnlock(KMutex);

/* A "tryable" mutex is one that supports the "trylock" operation, which is
   non-blocking. Make sure you read the comments in NT/os-thread.c before
   using either of these. These functions exist only because of limitations
   of the Win32s API, and can go away when we drop support for Win98/ME.
   On Unix, all our mutexes are "tryable", but you should use
   New_KMutexTryable to create your mutex if you need to call the
   KMutexTryLock operation. The KMutex returned by New_KMutexTryable supports
   all the same operations as ones created by New_KMutex.
*/
mbool KMutexTryLock(KMutex);

/*
 KCondition objects hold handles to the OS specific implementation 
 of condition objects.  They also hold a mutex since pthread_cond_wait 
 also takes a mutex.
*/

typedef struct st_KCondition
	{
	void* condition_handle;
	}* KCondition;

KCondition New_KCondition(void);

void Delete_KCondition(KCondition);

void KConditionWait(KCondition, KMutex);

/* Return TRUE iff the wait timed out. */
mbool KConditionTimedWait(KCondition, KMutex, long);

void KConditionSignal(KCondition);

/*
 Wait until the thread kt exits.  Returns TRUE if the 
 thread really exited.
*/

mbool KThreadWaitForExit(KThread kt);

int getProcessPriorityClass(void);
mbool setProcessPriorityClass(int priority);
KMutex New_KMutex_Recursive(void);

/* Thread Local storage struct and functions */
typedef struct st_ThreadLocalStorage
{
	void* tls_handle;
}* KThreadLocalStorage;

KThreadLocalStorage New_KThreadLocalStorage(void);
void Delete_KThreadLocalStorage(KThreadLocalStorage);

void KThreadLocalStorageSet(KThreadLocalStorage, void *);
void * KThreadLocalStorageGet(KThreadLocalStorage);

mint KThreadID(void);

void KThread_initStartStopFunctions(void);

uint32_t KThread_addStartFunction(void (*startFn)(void));
uint32_t KThread_addStopFunction(void (*stopFn)(void));

/*
 Run all registered thread-start functions.
 To be called by the OS-specific code when a thread is started.
*/
void KThread_runStartFunctions(void);

/*
 Run all registered thread-stop functions.
 To be called by the OS-specific code when a thread is stopped.
*/
void KThread_runStopFunctions(void);

#ifdef __cplusplus
}
#endif

#endif /* OS_THREAD_H */


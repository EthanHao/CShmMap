/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   rwlock.cpp
 * Author: ethan
 * 
 * Created on February 8, 2017, 5:54 PM
 */

#include "rwlock.h"

rwlock::rwlock() {
    init();
}


rwlock::~rwlock() {
  pthread_rwlockattr_destroy(&mpthreadRWAttr);
  pthread_rwlock_destroy(&mpthreadRWlock);
}

void rwlock::readLock()
{
    pthread_rwlock_rdlock(&mpthreadRWlock);
}
void rwlock::writeLock()
{
    pthread_rwlock_wrlock(&mpthreadRWlock);
}
void rwlock::unlock()
{
    pthread_rwlock_unlock(&mpthreadRWlock);
}
void rwlock::init()
{
 pthread_rwlockattr_init(&mpthreadRWAttr);
  pthread_rwlockattr_setpshared(&mpthreadRWAttr, PTHREAD_PROCESS_SHARED);
  pthread_rwlock_init(&mpthreadRWlock, &mpthreadRWAttr);
}


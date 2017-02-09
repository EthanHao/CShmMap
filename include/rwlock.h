/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   rwlock.h
 * Author: ethan
 *
 * Created on February 8, 2017, 5:54 PM
 */

#ifndef RWLOCK_H
#define RWLOCK_H

#include "pthread.h"

//a rwlock cross process

class rwlock {
public:
    rwlock(); 
    virtual ~rwlock();
    rwlock(const rwlock& orig) = delete;
    
public:
    void readLock();
    void writeLock();
    void unlock();
    void init();
private:
    pthread_rwlock_t mpthreadRWlock;
    pthread_rwlockattr_t mpthreadRWAttr;
};

#endif /* RWLOCK_H */


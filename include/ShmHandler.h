/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ShmHandler.h
 * Author: ethan
 *
 * Created on February 8, 2017, 2:04 PM
 */

#ifndef SHMHANDLER_H
#define SHMHANDLER_H

#include "VSemaphore.h"
//Connect this local memory cache with the priviledge (Readonly, ReadWrite)
//retrieve data (read a kind of data)
//modify data  (modify a kind of data)
template<class T>
class ShmHandler<T> {
public:
    ShmHandler();
    ShmHandler(const ShmHandler& orig);
    virtual ~ShmHandler();
private:
    int mShmKey; //KeyID
    int mProcessID[10];  // a list of process which connected this handler
    pthread_rwlock_t;
    
public:
    bool connect(int key);
    bool get(const char * nKey, void * & nRet) ;
    bool set(const char * nkey, const void * & nBuf, int nSize);

};

#endif /* SHMHANDLER_H */


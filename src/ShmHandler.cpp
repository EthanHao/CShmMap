/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "rwlock.h"
#include <iostream>
#include  <stdio.h>
#include  <string.h>
#include  <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <pthread.h>

int gcount = 0;

struct sShare {
    int mncount;
    rwlock mlock;
};

int main() {
    sShare *lShare;
    //create shared memory
    int shmid = shmget(ftok(".", 'a'), sizeof(sShare), 0666|IPC_CREAT);
    //attach 
    lShare =(sShare *)shmat(shmid , 0, 0);
    lShare->mncount = 0;
    new (&lShare->mlock) rwlock();
    //lShare->mlock.init();
    for (int i = 0; i < 2; i++) {
        if (fork() == 0) {
           
            for (int i = 0; i < 1000; i++) {
                
                lShare->mlock.readLock();
                std::cout << getpid() << "read" << lShare->mncount << std::endl;
                lShare->mlock.unlock();

            }
            return 0;
        }
    }


    for(int i = 0; i < 500; i++) {
        lShare->mlock.writeLock();
        lShare->mncount++; 
        std::cout << getpid() << "write" << lShare->mncount << std::endl;
        lShare->mlock.unlock();
    }
    
    //wait all 
    usleep(10000);
    
    return 0;
}
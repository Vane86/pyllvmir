#ifndef MODULE_H
#define MODULE_H

#include <llvm/IR/Module.h>
#include <llvm/IRReader/IRReader.h>
#include <llvm/Support/SourceMgr.h>


extern "C" {
    void init();
    void clear();
    
    void* parseIRFile_wrap(char*);  // returns ModulePtr
}

#endif


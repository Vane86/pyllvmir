#include "module.h"

using namespace llvm;

LLVMContext* global_context;
SMDiagnostic* global_err;

void init()
{
    global_context = new LLVMContext();
    global_err = new SMDiagnostic();
}

void clear()
{
    delete global_context;
    delete global_err;
}

void* parseIRFile_wrap(char* file_path)  // returns ModulePtr
{
    std::unique_ptr<Module> mod_ptr = parseIRFile(file_path, *global_err, *global_context);
    Module* mod = mod_ptr.get();

    if (!mod) {
        global_err->print("", errs());
        return 0;
    }
    
    return (void*) mod;
}



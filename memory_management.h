/*
Copyright (c) 2013, peter.ducai@gmail.com
https://github.com/daemonna/jobdsigner
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

* Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.

* Redistributions in binary form must reproduce the above copyright notice, this
  list of conditions and the following disclaimer in the documentation and/or
  other materials provided with the distribution.

* Neither the name of the {organization} nor the names of its
  contributors may be used to endorse or promote products derived from
  this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef MEMORY_MANAGEMENT_H
#define	MEMORY_MANAGEMENT_H

#ifdef	__cplusplus
extern "C" {
#endif

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#include <sys/types.h>
#include <sys/sysinfo.h>
#include <inttypes.h>
#include "global.h"

#define MAX_MEM_LOAD 90

int64_t free_memory;
int64_t total_memory;
int64_t used_memory;

int64_t  get_totalmem(void) {
    struct sysinfo memInfo;

    sysinfo(&memInfo);
    int64_t totalVirtualMem = memInfo.totalram;

    totalVirtualMem = totalVirtualMem/1024/1024;
    return totalVirtualMem;
}

int64_t  get_freemem(void) {
    struct sysinfo memInfo;

    sysinfo(&memInfo);
    int64_t freeVirtualMem = memInfo.freeram;

    freeVirtualMem = freeVirtualMem/1024/1024;
    return freeVirtualMem;
}

void check_limits(){
    int64_t allowed=get_totalmem();
    allowed=(allowed/100)*MAX_MEM_LOAD;
    printf("Memory should NOT exceed %" PRId64 " MB \n", allowed);
}

void update_memory_stats(void){
    free_memory = get_freemem();
    total_memory = get_totalmem();
    used_memory = total_memory-free_memory;
}

void print_memory_stats(void){ 
    total_memory = get_totalmem();
    free_memory = get_freemem();
    used_memory = total_memory - free_memory;
    
    printf(ANSI_COLOR_YELLOW     "\n[Memory stats]"     ANSI_COLOR_RESET "\n");
    printf("total memory=%" PRId64 " \n", total_memory);
    printf("free memory=%" PRId64 " \n", free_memory);
    printf("used memory=%" PRId64 " \n", used_memory);
}

#ifdef	__cplusplus
}
#endif

#endif	/* MEMORY_MANAGEMENT_H */


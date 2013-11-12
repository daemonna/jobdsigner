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

#ifndef DATA_STORAGE_H
#define	DATA_STORAGE_H

#include "memory_management.h"


#ifdef	__cplusplus
extern "C" {
#endif
    
#include <time.h>
    
    //JD STATS
    extern time_t jd_start;
    extern time_t jd_uptime;

    //MEMORY STATS
    extern int64_t total_memory;
    extern int64_t free_memory;
    extern int64_t used_memory;
    extern int8_t max_allowed_memory; //in percents

    //JOB STATS
    extern int64_t total_jobs;
    extern int64_t ready_jobs;
    extern int64_t running_jobs;
    extern int64_t waiting_jobs;
    extern int64_t deprecated_jobs;
    


#ifdef	__cplusplus
}
#endif

#endif	/* DATA_STORAGE_H */


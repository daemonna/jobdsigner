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

#ifndef JOB_MANAGEMENT_H
#define	JOB_MANAGEMENT_H

#ifdef	__cplusplus
extern "C" {
#endif

#include <time.h>
#include "global.h"
#include "role_management.h"

#define MAX_SUITES 100

    enum job_status {
        READY = 1,
        RUNNING,
        WAITING,
        DEPRECATED
    };

    enum job_result {
        NONE = 1,
        PASSED,
        FAILED
    };

    enum job_type {
        CLI = 1,
        SSH,  //FOR ALL REMOTE JOBS
        DB
    };
    
    enum job_reaction {
        MANUAL,       //for manual start
        SCHEDULED,  //for CRON like functionality
        TRIGGERED   //for other triggers (source control commit hook)
    };

    struct job {
        int64_t id;
        char *name;
        char *description;
        enum job_type *type;
        char *command;
        enum job_status *status;
        time_t start;
        time_t end;
        int8_t in_condition_counter;
        int8_t out_condition_counter;
        enum job_result *result;
    };
    
    
    
        
    struct suite {
        int64_t id;
        char *name;
        char *description;
        struct role *owner;
        struct job *initial_job;
        
        char *schedule_time[6]; //IN CRON FORMAT
        //* * * * * *
        //| | | | | | 
        //| | | | | +-- Year              (range: 1900-3000)
        //| | | | +---- Day of the Week   (range: 1-7, 1 standing for Monday)
        //| | | +------ Month of the Year (range: 1-12)
        //| | +-------- Day of the Month  (range: 1-31)
        //| +---------- Hour              (range: 0-23)
        //+------------ Minute            (range: 0-59)
        //@yearly (or @annually) 	Run once a year at midnight in the morning of January 1 	0 0 1 1 *
        //@monthly 	Run once a month at midnight in the morning of the first day of the month 	0 0 1 * *
        //@weekly 	Run once a week at midnight in the morning of Sunday 	0 0 * * 0
        //@daily 	Run once a day at midnight 	0 0 * * *
        //@hourly 	Run once an hour at the beginning of the hour 	0 * * * *
    };

    void initialize_engine(void) {
        printf("\nEngine initialization..\n");
    }



#ifdef	__cplusplus
}
#endif

#endif	/* JOB_MANAGEMENT_H */


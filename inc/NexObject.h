
#ifndef __NEXOBJECT_H__
#define __NEXOBJECT_H__
#include "NexConfig.h"
#include "Utilities.h"

typedef void (*NexTouchEventCb)(void *ptr);

struct NexObject
{
    unsigned short __pid;      /* Page ID */
    unsigned short __cid;      /* Component ID */
    char __name[16]; /* An unique name */
    NexTouchEventCb __cb_push;
    void *__cbpush_ptr;
    NexTouchEventCb __cb_pop;
    void *__cbpop_ptr;
};

#endif

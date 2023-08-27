/*
 * Copyright (c) 2016, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

/*
 * Generated by erpcgen 1.11.0 on Sun Aug 27 17:53:43 2023.
 *
 * AUTOGENERATED - DO NOT EDIT
 */


#include "Caculator_server.h"
#if ERPC_ALLOCATION_POLICY == ERPC_ALLOCATION_POLICY_DYNAMIC
#include <new>
#include "erpc_port.h"
#endif
#include "erpc_manually_constructed.hpp"

#if 11100 != ERPC_VERSION_NUMBER
#error "The generated shim code version is different to the rest of eRPC code."
#endif

using namespace erpc;
using namespace std;

#if ERPC_NESTED_CALLS_DETECTION
extern bool nestingDetection;
#endif

ERPC_MANUALLY_CONSTRUCTED_STATIC(IMath_service, s_IMath_service);

ERPC_MANUALLY_CONSTRUCTED_STATIC(ICounter_service, s_ICounter_service);



// Call the correct server shim based on method unique ID.
erpc_status_t IMath_service::handleInvocation(uint32_t methodId, uint32_t sequence, Codec * codec, MessageBufferFactory *messageFactory)
{
    erpc_status_t erpcStatus;
    switch (methodId)
    {
        case kIMath_add_id:
        {
            erpcStatus = add_shim(codec, messageFactory, sequence);
            break;
        }

        default:
        {
            erpcStatus = kErpcStatus_InvalidArgument;
            break;
        }
    }

    return erpcStatus;
}

// Server shim for add of IMath interface.
erpc_status_t IMath_service::add_shim(Codec * codec, MessageBufferFactory *messageFactory, uint32_t sequence)
{
    erpc_status_t err = kErpcStatus_Success;

    int32_t num_1;
    int32_t num_2;
    int32_t result;

    // startReadMessage() was already called before this shim was invoked.

    codec->read(num_1);

    codec->read(num_2);

    err = codec->getStatus();
    if (err == kErpcStatus_Success)
    {
        // Invoke the actual served function.
#if ERPC_NESTED_CALLS_DETECTION
        nestingDetection = true;
#endif
        result = add(num_1, num_2);
#if ERPC_NESTED_CALLS_DETECTION
        nestingDetection = false;
#endif

        // preparing MessageBuffer for serializing data
        err = messageFactory->prepareServerBufferForSend(codec->getBuffer());
    }

    if (err == kErpcStatus_Success)
    {
        // preparing codec for serializing data
        codec->reset();

        // Build response message.
        codec->startWriteMessage(kReplyMessage, kIMath_service_id, kIMath_add_id, sequence);

        codec->write(result);

        err = codec->getStatus();
    }

    return err;
}

// Call the correct server shim based on method unique ID.
erpc_status_t ICounter_service::handleInvocation(uint32_t methodId, uint32_t sequence, Codec * codec, MessageBufferFactory *messageFactory)
{
    erpc_status_t erpcStatus;
    switch (methodId)
    {
        case kICounter_set_counter_id:
        {
            erpcStatus = set_counter_shim(codec, messageFactory, sequence);
            break;
        }

        case kICounter_get_counter_id:
        {
            erpcStatus = get_counter_shim(codec, messageFactory, sequence);
            break;
        }

        default:
        {
            erpcStatus = kErpcStatus_InvalidArgument;
            break;
        }
    }

    return erpcStatus;
}

// Server shim for set_counter of ICounter interface.
erpc_status_t ICounter_service::set_counter_shim(Codec * codec, MessageBufferFactory *messageFactory, uint32_t sequence)
{
    erpc_status_t err = kErpcStatus_Success;

    int32_t counter;

    // startReadMessage() was already called before this shim was invoked.

    codec->read(counter);

    err = codec->getStatus();
    if (err == kErpcStatus_Success)
    {
        // Invoke the actual served function.
#if ERPC_NESTED_CALLS_DETECTION
        nestingDetection = true;
#endif
        set_counter(counter);
#if ERPC_NESTED_CALLS_DETECTION
        nestingDetection = false;
#endif

        // preparing MessageBuffer for serializing data
        err = messageFactory->prepareServerBufferForSend(codec->getBuffer());
    }

    if (err == kErpcStatus_Success)
    {
        // preparing codec for serializing data
        codec->reset();

        // Build response message.
        codec->startWriteMessage(kReplyMessage, kICounter_service_id, kICounter_set_counter_id, sequence);

        err = codec->getStatus();
    }

    return err;
}

// Server shim for get_counter of ICounter interface.
erpc_status_t ICounter_service::get_counter_shim(Codec * codec, MessageBufferFactory *messageFactory, uint32_t sequence)
{
    erpc_status_t err = kErpcStatus_Success;

    int32_t result;

    // startReadMessage() was already called before this shim was invoked.

    err = codec->getStatus();
    if (err == kErpcStatus_Success)
    {
        // Invoke the actual served function.
#if ERPC_NESTED_CALLS_DETECTION
        nestingDetection = true;
#endif
        result = get_counter();
#if ERPC_NESTED_CALLS_DETECTION
        nestingDetection = false;
#endif

        // preparing MessageBuffer for serializing data
        err = messageFactory->prepareServerBufferForSend(codec->getBuffer());
    }

    if (err == kErpcStatus_Success)
    {
        // preparing codec for serializing data
        codec->reset();

        // Build response message.
        codec->startWriteMessage(kReplyMessage, kICounter_service_id, kICounter_get_counter_id, sequence);

        codec->write(result);

        err = codec->getStatus();
    }

    return err;
}

erpc_service_t create_IMath_service(void)
{
    erpc_service_t service;

#if ERPC_ALLOCATION_POLICY == ERPC_ALLOCATION_POLICY_DYNAMIC
    service = new (nothrow) IMath_service();
#else
    if (s_IMath_service.isUsed())
    {
        service = NULL;
    }
    else
    {
        s_IMath_service.construct();
        service = s_IMath_service.get();
    }
#endif

    return service;
}

void destroy_IMath_service(erpc_service_t service)
{
#if ERPC_ALLOCATION_POLICY == ERPC_ALLOCATION_POLICY_DYNAMIC
    erpc_assert(service != NULL);
    delete (IMath_service *)service;
#else
    (void)service;
    erpc_assert(service == s_IMath_service.get());
    s_IMath_service.destroy();
#endif
}


erpc_service_t create_ICounter_service(void)
{
    erpc_service_t service;

#if ERPC_ALLOCATION_POLICY == ERPC_ALLOCATION_POLICY_DYNAMIC
    service = new (nothrow) ICounter_service();
#else
    if (s_ICounter_service.isUsed())
    {
        service = NULL;
    }
    else
    {
        s_ICounter_service.construct();
        service = s_ICounter_service.get();
    }
#endif

    return service;
}

void destroy_ICounter_service(erpc_service_t service)
{
#if ERPC_ALLOCATION_POLICY == ERPC_ALLOCATION_POLICY_DYNAMIC
    erpc_assert(service != NULL);
    delete (ICounter_service *)service;
#else
    (void)service;
    erpc_assert(service == s_ICounter_service.get());
    s_ICounter_service.destroy();
#endif
}

/*
 * Copyright © 2013-2014  Rinat Ibragimov
 *
 * This file is part of FreshPlayerPlugin.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include "ppb_buffer.h"
#include <stdlib.h>
#include "trace.h"


PP_Resource
ppb_buffer_create(PP_Instance instance, uint32_t size_in_bytes)
{
    return 0;
}

PP_Bool
ppb_buffer_is_buffer(PP_Resource resource)
{
    return PP_TRUE;
}

PP_Bool
ppb_buffer_describe(PP_Resource resource, uint32_t *size_in_bytes)
{
    return PP_FALSE;
}

void *
ppb_buffer_map(PP_Resource resource)
{
    return NULL;
}

void
ppb_buffer_unmap(PP_Resource resource)
{
}


// trace wrappers
TRACE_WRAPPER
PP_Resource
trace_ppb_buffer_create(PP_Instance instance, uint32_t size_in_bytes)
{
    trace_info("[PPB] {zilch} %s instance=%d, size_in_bytes=%u\n", __func__+6,
               instance, size_in_bytes);
    return ppb_buffer_create(instance, size_in_bytes);
}

TRACE_WRAPPER
PP_Bool
trace_ppb_buffer_is_buffer(PP_Resource resource)
{
    trace_info("[PPB] {zilch} %s resource=%d\n", __func__+6, resource);
    return ppb_buffer_is_buffer(resource);
}

TRACE_WRAPPER
PP_Bool
trace_ppb_buffer_describe(PP_Resource resource, uint32_t *size_in_bytes)
{
    trace_info("[PPB] {zilch} %s resource=%d\n", __func__+6, resource);
    return ppb_buffer_describe(resource, size_in_bytes);
}

TRACE_WRAPPER
void *
trace_ppb_buffer_map(PP_Resource resource)
{
    trace_info("[PPB] {zilch} %s resource=%d\n", __func__+6, resource);
    return ppb_buffer_map(resource);
}

TRACE_WRAPPER
void
trace_ppb_buffer_unmap(PP_Resource resource)
{
    trace_info("[PPB] {zilch} %s resource=%d\n", __func__+6, resource);
    ppb_buffer_unmap(resource);
}


const struct PPB_Buffer_Dev_0_4 ppb_buffer_dev_interface_0_4 = {
    .Create =   TWRAPZ(ppb_buffer_create),
    .IsBuffer = TWRAPZ(ppb_buffer_is_buffer),
    .Describe = TWRAPZ(ppb_buffer_describe),
    .Map =      TWRAPZ(ppb_buffer_map),
    .Unmap =    TWRAPZ(ppb_buffer_unmap),
};

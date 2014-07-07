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

#include "ppb_file_io.h"
#include <stdlib.h>
#include <ppapi/c/pp_errors.h>
#include <inttypes.h>
#include "trace.h"
#include "pp_resource.h"


int32_t
ppb_file_io_request_os_file_handle(PP_Resource file_io, PP_FileHandle *handle,
                                   struct PP_CompletionCallback callback)
{
    return 0;
}

PP_Resource
ppb_file_io_create(PP_Instance instance)
{
    PP_Resource file_io = pp_resource_allocate(PP_RESOURCE_FILE_IO, instance);
    return file_io;
}

void
ppb_file_io_destroy(void *p)
{
}

PP_Bool
ppb_file_io_is_file_io(PP_Resource resource)
{
    return pp_resource_get_type(resource) == PP_RESOURCE_FILE_IO;
}

int32_t
ppb_file_io_open(PP_Resource file_io, PP_Resource file_ref, int32_t open_flags,
                 struct PP_CompletionCallback callback)
{
    return PP_OK;
}

int32_t
ppb_file_io_query(PP_Resource file_io, struct PP_FileInfo *info,
                  struct PP_CompletionCallback callback)
{
    return PP_OK;
}

int32_t
ppb_file_io_touch(PP_Resource file_io, PP_Time last_access_time, PP_Time last_modified_time,
                  struct PP_CompletionCallback callback)
{
    return PP_OK;
}

int32_t
ppb_file_io_read(PP_Resource file_io, int64_t offset, char *buffer, int32_t bytes_to_read,
                 struct PP_CompletionCallback callback)
{
    return PP_OK;
}

int32_t
ppb_file_io_write(PP_Resource file_io, int64_t offset, const char *buffer, int32_t bytes_to_write,
                  struct PP_CompletionCallback callback)
{
    return PP_OK;
}

int32_t
ppb_file_io_set_length(PP_Resource file_io, int64_t length, struct PP_CompletionCallback callback)
{
    return PP_OK;
}

int32_t
ppb_file_io_flush(PP_Resource file_io, struct PP_CompletionCallback callback)
{
    return PP_OK;
}

void
ppb_file_io_close(PP_Resource file_io)
{
}

int32_t
ppb_file_io_read_to_array(PP_Resource file_io, int64_t offset, int32_t max_read_length,
                          struct PP_ArrayOutput *output, struct PP_CompletionCallback callback)
{
    return PP_OK;
}


// trace wrappers
TRACE_WRAPPER
int32_t
trace_ppb_file_io_request_os_file_handle(PP_Resource file_io, PP_FileHandle *handle,
                                         struct PP_CompletionCallback callback)
{
    trace_info("[PPB] {zilch} %s file_io=%d, callback={.func=%p, .user_data=%p, .flags=%u}\n",
               __func__+6, file_io, callback.func, callback.user_data, callback.flags);
    return ppb_file_io_request_os_file_handle(file_io, handle, callback);
}

TRACE_WRAPPER
PP_Resource
trace_ppb_file_io_create(PP_Instance instance)
{
    trace_info("[PPB] {full} %s instance=%d\n", __func__+6, instance);
    return ppb_file_io_create(instance);
}

TRACE_WRAPPER
PP_Bool
trace_ppb_file_io_is_file_io(PP_Resource resource)
{
    trace_info("[PPB] {full} %s resource=%d\n", __func__+6, resource);
    return ppb_file_io_is_file_io(resource);
}

TRACE_WRAPPER
int32_t
trace_ppb_file_io_open(PP_Resource file_io, PP_Resource file_ref, int32_t open_flags,
                       struct PP_CompletionCallback callback)
{
    trace_info("[PPB] {zilch} %s file_io=%d, file_ref=%d, open_flags=%u, callback={.func=%p, "
               ".user_data=%p, .flags=%u}\n", __func__+6, file_io, file_ref, open_flags,
               callback.func, callback.user_data, callback.flags);
    return ppb_file_io_open(file_io, file_ref, open_flags, callback);
}

TRACE_WRAPPER
int32_t
trace_ppb_file_io_query(PP_Resource file_io, struct PP_FileInfo *info,
                        struct PP_CompletionCallback callback)
{
    trace_info("[PPB] {zilch} %s file_io=%d, callback={.func=%p, .user_data=%p, .flags=%u}\n",
               __func__+6, file_io, callback.func, callback.user_data, callback.flags);
    return ppb_file_io_query(file_io, info, callback);
}

TRACE_WRAPPER
int32_t
trace_ppb_file_io_touch(PP_Resource file_io, PP_Time last_access_time, PP_Time last_modified_time,
                        struct PP_CompletionCallback callback)
{
    trace_info("[PPB] {zilch} %s file_io=%d, last_access_time=%f, last_modified_time=%f, "
               "callback={.func=%p, .user_data=%p, .flags=%u}\n", __func__+6, file_io,
               last_access_time, last_modified_time, callback.func, callback.user_data,
               callback.flags);
    return ppb_file_io_touch(file_io, last_access_time, last_modified_time, callback);
}

TRACE_WRAPPER
int32_t
trace_ppb_file_io_read(PP_Resource file_io, int64_t offset, char *buffer, int32_t bytes_to_read,
                       struct PP_CompletionCallback callback)
{
    trace_info("[PPB] {zilch} %s file_io=%d, offset=%"PRId64", bytes_to_read=%d, "
               "callback={.func=%p, .user_data=%p, .flags=%u}\n", __func__+6, file_io, offset,
               bytes_to_read, callback.func, callback.user_data, callback.flags);
    return ppb_file_io_read(file_io, offset, buffer, bytes_to_read, callback);
}

TRACE_WRAPPER
int32_t
trace_ppb_file_io_write(PP_Resource file_io, int64_t offset, const char *buffer,
                        int32_t bytes_to_write, struct PP_CompletionCallback callback)
{
    trace_info("[PPB] {zilch} %s file_io=%d, offset=%"PRId64", bytes_to_write=%d, "
               "callback={.func=%p, .user_data=%p, .flags=%u}\n", __func__+6, file_io, offset,
               bytes_to_write, callback.func, callback.user_data, callback.flags);
    return ppb_file_io_write(file_io, offset, buffer, bytes_to_write, callback);
}

TRACE_WRAPPER
int32_t
trace_ppb_file_io_set_length(PP_Resource file_io, int64_t length,
                             struct PP_CompletionCallback callback)
{
    trace_info("[PPB] {zilch} %s file_io=%d, length=%"PRId64", callback={.func=%p, .user_data=%p, "
               ".flags=%u}\n", __func__+6, file_io, length, callback.func, callback.user_data,
               callback.flags);
    return ppb_file_io_set_length(file_io, length, callback);
}

TRACE_WRAPPER
int32_t
trace_ppb_file_io_flush(PP_Resource file_io, struct PP_CompletionCallback callback)
{
    trace_info("[PPB] {zilch} %s file_io=%d, callback={.func=%p, .user_data=%p, .flags=%u}\n",
               __func__+6, file_io, callback.func, callback.user_data, callback.flags);
    return ppb_file_io_flush(file_io, callback);
}

TRACE_WRAPPER
void
trace_ppb_file_io_close(PP_Resource file_io)
{
    trace_info("[PPB] {zilch} %s file_io=%d\n", __func__+6, file_io);
    return ppb_file_io_close(file_io);
}

TRACE_WRAPPER
int32_t
trace_ppb_file_io_read_to_array(PP_Resource file_io, int64_t offset, int32_t max_read_length,
                                struct PP_ArrayOutput *output, struct PP_CompletionCallback callback)
{
    trace_info("[PPB] {zilch} %s file_io=%d, offset=%"PRId64", max_read_length=%d, "
               "callback={.func=%p, .user_data=%p, .flags=%u}\n", __func__+6, file_io, offset,
               max_read_length, callback.func, callback.user_data, callback.flags);
    return ppb_file_io_read_to_array(file_io, offset, max_read_length, output, callback);
}


const struct PPB_FileIO_Private_0_1 ppb_file_io_private_interface_0_1 = {
    .RequestOSFileHandle = TWRAPZ(ppb_file_io_request_os_file_handle),
};

const struct PPB_FileIO_1_1 ppb_file_io_interface_1_1 = {
    .Create =       TWRAPF(ppb_file_io_create),
    .IsFileIO =     TWRAPF(ppb_file_io_is_file_io),
    .Open =         TWRAPZ(ppb_file_io_open),
    .Query =        TWRAPZ(ppb_file_io_query),
    .Touch =        TWRAPZ(ppb_file_io_touch),
    .Read =         TWRAPZ(ppb_file_io_read),
    .Write =        TWRAPZ(ppb_file_io_write),
    .SetLength =    TWRAPZ(ppb_file_io_set_length),
    .Flush =        TWRAPZ(ppb_file_io_flush),
    .Close =        TWRAPZ(ppb_file_io_close),
    .ReadToArray =  TWRAPZ(ppb_file_io_read_to_array),
};

const struct PPB_FileIO_1_0 ppb_file_io_interface_1_0 = {
    .Create =       TWRAPF(ppb_file_io_create),
    .IsFileIO =     TWRAPF(ppb_file_io_is_file_io),
    .Open =         TWRAPZ(ppb_file_io_open),
    .Query =        TWRAPZ(ppb_file_io_query),
    .Touch =        TWRAPZ(ppb_file_io_touch),
    .Read =         TWRAPZ(ppb_file_io_read),
    .Write =        TWRAPZ(ppb_file_io_write),
    .SetLength =    TWRAPZ(ppb_file_io_set_length),
    .Flush =        TWRAPZ(ppb_file_io_flush),
    .Close =        TWRAPZ(ppb_file_io_close),
};
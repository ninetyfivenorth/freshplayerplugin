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

#ifndef FPP__PPB_MESSAGE_LOOP_H
#define FPP__PPB_MESSAGE_LOOP_H

#include <ppapi/c/ppb_message_loop.h>


PP_Resource
ppb_message_loop_create(PP_Instance instance);

void
ppb_message_loop_destroy(void *p);

PP_Resource
ppb_message_loop_get_for_main_thread(void);

int32_t
ppb_message_loop_proclaim_this_thread_main(void);

PP_Resource
ppb_message_loop_get_for_browser_thread(void);

int32_t
ppb_message_loop_proclaim_this_thread_browser(void);

PP_Resource
ppb_message_loop_get_current(void);

int32_t
ppb_message_loop_attach_to_current_thread(PP_Resource message_loop);

int32_t
ppb_message_loop_run(PP_Resource message_loop);

int32_t
ppb_message_loop_run_nested(PP_Resource message_loop, int nested);

int32_t
ppb_message_loop_post_work_with_result(PP_Resource message_loop,
                                       struct PP_CompletionCallback callback, int64_t delay_ms,
                                       int32_t result_to_pass);

int32_t
ppb_message_loop_post_work(PP_Resource message_loop, struct PP_CompletionCallback callback,
                           int64_t delay_ms);

int32_t
ppb_message_loop_post_quit(PP_Resource message_loop, PP_Bool should_destroy);

void
ppb_message_loop_mark_thread_unsuitable(void);

#endif // FPP__PPB_MESSAGE_LOOP_H

/*
 * Copyright (c) 2014-2018 Cesanta Software Limited
 * All rights reserved
 *
 * Licensed under the Apache License, Version 2.0 (the ""License"");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an ""AS IS"" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <stdio.h>

#include "mgos.h"

static void timer_cb(void *arg) {
  static int current_level = 1;
  LOG(LL_INFO, ("%s", (current_level ? "Tick" : "Tock")));
  current_level ^= 1;
  (void) arg;
}

enum mgos_app_init_result mgos_app_init(void) {
  printf("Hello, world!\n");
  mgos_set_timer(1000 /* ms */, true /* repeat */, timer_cb, NULL);
  return MGOS_APP_INIT_SUCCESS;
}

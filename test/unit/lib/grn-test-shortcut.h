/* -*- c-basic-offset: 2; coding: utf-8 -*- */
/*
  Copyright (C) 2010  Kouhei Sutou <kou@clear-code.com>

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License version 2.1 as published by the Free Software Foundation.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#ifndef __GRN_TEST_SHORTCUT_H__
#define __GRN_TEST_SHORTCUT_H__

#define get_object(name)                        \
  grn_ctx_get(context, (name), strlen((name)))

#define send_command(command)                   \
  grn_test_send_command(context, (command))

#define assert_send_command(command, ...)                       \
  cut_trace_with_info_expression(                               \
    cut_test_with_user_message(                                 \
      grn_test_send_command((context), (command)),              \
      __VA_ARGS__),                                             \
    grn_assert_send_command(context, command))

#define assert_send_commands(commands, ...)             \
  cut_trace_with_info_expression(                       \
    cut_test_with_user_message(                         \
      grn_test_send_commands((context), (commands)),    \
      __VA_ARGS__),                                     \
    grn_assert_send_commands(context, commands))

#endif

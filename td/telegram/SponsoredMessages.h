//
// Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com) 2014-2021
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
#pragma once

#include "td/telegram/DialogId.h"
#include "td/telegram/td_api.h"

#include "td/actor/PromiseFuture.h"

#include "td/utils/common.h"

namespace td {

class Td;

void get_sponsored_messages(Td *td, DialogId dialog_id,
                            Promise<td_api::object_ptr<td_api::sponsoredMessages>> &&promise);

}  // namespace td

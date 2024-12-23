//
// Copyright Aliaksei Levin (levlam@telegram.org), Arseny Smirnov (arseny30@gmail.com) 2014-2024
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//
#pragma once

#include "td/telegram/files/FileId.h"
#include "td/telegram/td_api.h"
#include "td/telegram/telegram_api.h"

#include "td/utils/common.h"
#include "td/utils/StringBuilder.h"

namespace td {

class Td;

class StarGiftAttributeModel {
  string name_;
  FileId sticker_file_id_;
  int32 rarity_permille_ = 0;

  friend bool operator==(const StarGiftAttributeModel &lhs, const StarGiftAttributeModel &rhs);

 public:
  StarGiftAttributeModel() = default;

  StarGiftAttributeModel(Td *td, telegram_api::object_ptr<telegram_api::starGiftAttributeModel> &&attribute);

  bool is_valid() const {
    return 0 < rarity_permille_ && rarity_permille_ <= 1000 && sticker_file_id_.is_valid();
  }

  td_api::object_ptr<td_api::upgradedGiftModel> get_upgraded_gift_model_object(const Td *td) const;

  template <class StorerT>
  void store(StorerT &storer) const;

  template <class ParserT>
  void parse(ParserT &parser);
};

bool operator==(const StarGiftAttributeModel &lhs, const StarGiftAttributeModel &rhs);

inline bool operator!=(const StarGiftAttributeModel &lhs, const StarGiftAttributeModel &rhs) {
  return !(lhs == rhs);
}

}  // namespace td

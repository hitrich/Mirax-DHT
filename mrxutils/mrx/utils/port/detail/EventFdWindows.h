
#pragma once

#include /utils/port/config.h"

#ifdef TD_EVENTFD_WINDOWS

#include /utils/common.h"
#include /utils/port/detail/NativeFd.h"
#include /utils/port/detail/PollableFd.h"
#include /utils/port/EventFdBase.h"
#include /utils/Status.h"

namespace td {
namespace detail {

class EventFdWindows final : public EventFdBase {
  NativeFd event_;

 public:
  EventFdWindows() = default;

  void init() override;

  bool empty() override;

  void close() override;

  Status get_pending_error() override TD_WARN_UNUSED_RESULT;

  PollableFdInfo &get_poll_info() override;

  void release() override;

  void acquire() override;

  void wait(int timeout_ms) override;
};

}  // namespace detail
}  // namespace td

#endif

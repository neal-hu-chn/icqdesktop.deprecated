#include "stdafx.h"
#include "event.h"

using namespace core;
using namespace tools;

autoreset_event::autoreset_event()
    : signalled_(false)
{
}


autoreset_event::~autoreset_event()
{
}

void autoreset_event::notify()
{
    {
        std::lock_guard<std::mutex> lock(mtx_);
        signalled_ = true;
    }

    cv_.notify_one();
}

void autoreset_event::wait()
{
    std::unique_lock<std::mutex> lock(mtx_);

    cv_.wait(lock, [&] { return signalled_; });

    signalled_ = false;
}

bool autoreset_event::wait_for(std::chrono::milliseconds _timeout)
{
    std::unique_lock<std::mutex> lock(mtx_);

    auto result = cv_.wait_for(lock, _timeout, [&] { return signalled_; });

    if (result)
        signalled_ = false;

    return result;
}
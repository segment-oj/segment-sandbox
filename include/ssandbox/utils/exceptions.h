// -*- C++ -*- Part of the Segment Sandbox Project

#ifndef SSANDBOX_UTILS_EXCEPTIONS_H
#define SSANDBOX_UTILS_EXCEPTIONS_H

#include <exception>
#include <stdexcept>
#include <string>

namespace ssandbox {

namespace utils {

namespace exceptions {

class syscall_error {
public:
    syscall_error(int errorno, std::string message, std::string function);
    ~syscall_error();

    const char* what() const throw();

private:
    std::string _message;
};

} // namespace exceptions

} // namespace utils

} // namespace ssandbox

#endif // SSANDBOX_UTILS_EXCEPTIONS_H
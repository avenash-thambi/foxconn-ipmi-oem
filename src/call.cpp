#include "sys_file_impl.hpp"
#include <memory>

auto file = std::make_unique<binstore::SysFileImpl>("/sys/bus/i2c/",
                                                    255);

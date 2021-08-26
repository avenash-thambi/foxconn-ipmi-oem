#pragma once

#include <fcntl.h>
#include <unistd.h>

#include <string>

namespace binstore
{

/**
 * @brief Represents a file that supports read/write semantics
 * TODO: leverage stdplus's support for smart file descriptors when it's ready.
 */
class SysFile
{
  public:
    virtual ~SysFile() = default;

    /**
     * @brief Reads content at pos to char* buffer
     * @param pos The byte pos into the file to read from
     * @param count How many bytes to read
     * @param buf Output data
     * @returns The size of data read
     * @throws std::system_error if read operation cannot be completed
     */
    virtual size_t readToBuf(size_t pos, size_t count, char* buf) const = 0;

    /**
     * @brief Writes all of data into file at pos
     * @param pos The byte pos to write
     * @returns void
     * @throws std::system_error if write operation cannot be completed or
     *         not all of the bytes can be written
     */
    virtual void writeStr(const std::string& data, size_t pos) = 0;
};

} // namespace binstore

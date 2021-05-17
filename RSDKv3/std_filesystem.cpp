#include "std_filesystem.h"
#include <sys/types.h>
#include <sys/stat.h>

std::string std::filesystem::path::string() const
{
    return m_str;
}

std::filesystem::path std::filesystem::path::filename() const
{
    for (int i = m_str.length() - 1; i >= 0; i--)
    {
        auto ch = m_str[i];
        if (ch == '\\'  || '/')
            return std::filesystem::path(m_str.substr(i + 1));
    }

    return std::filesystem::path(m_str);
}

std::filesystem::path std::filesystem::directory_entry::path() const
{
    return m_path;
}

bool std::filesystem::directory_entry::is_directory() const
{
    return std::filesystem::is_directory(m_path);
}

bool std::filesystem::directory_entry::is_regular_file() const
{
    struct stat info;
    return stat(m_path.string().c_str(), &info) == 0 && S_ISREG(info.st_mode);
}

bool std::filesystem::exists(const std::filesystem::path& p)
{
    struct stat info;
    return stat(p.string().c_str(), &info) == 0;
}

bool std::filesystem::is_directory(const std::filesystem::path& p)
{
    struct stat info;
    return stat(p.string().c_str(), &info) == 0 && S_ISDIR(info.st_mode);
}

std::list<std::filesystem::directory_entry> std::filesystem::directory_iterator(const std::filesystem::path& p)
{
    std::list<std::filesystem::directory_entry> list;
    // TODO

    return list;
}

std::list<std::filesystem::directory_entry> std::filesystem::recursive_directory_iterator(const std::filesystem::path& p)
{
    std::list<std::filesystem::directory_entry> list;
    // TODO

    return list;
}

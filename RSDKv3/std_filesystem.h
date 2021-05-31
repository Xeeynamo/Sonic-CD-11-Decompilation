#pragma once
#include <string>
#include <exception>
#include <list>

namespace std { namespace filesystem {
    class path
    {
        std::string m_str;
    public:
        path(const std::string& str) :
            m_str(str)
        { }

        std::string string() const;
        std::filesystem::path filename() const;
    };

    class filesystem_error : public std::exception
    { };

    class directory_entry
    {
        std::filesystem::path m_path;
    public:
        directory_entry(const std::filesystem::path& p);

        std::filesystem::path path() const;
        bool is_directory() const;
        bool is_regular_file() const;
    };
    
    bool exists(const std::filesystem::path& p);
    bool is_directory(const std::filesystem::path& p);
    std::list<directory_entry> directory_iterator(const std::filesystem::path& p);
    std::list<directory_entry> recursive_directory_iterator(const std::filesystem::path& p);
}}
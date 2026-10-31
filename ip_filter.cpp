
#include "ip_filter.h"
#include <cstdint>


std::vector<std::string> split(const std::string &str, char d)
{
    std::vector<std::string> r;
    std::string::size_type start = 0;
    std::string::size_type stop = str.find_first_of(d);
    while (stop != std::string::npos)
    {
        r.push_back(str.substr(start, stop - start));
        start = stop + 1;
        stop = str.find_first_of(d, start);
    }
    r.push_back(str.substr(start));
    return r;
}

using ip_t = std::tuple<uint8_t, uint8_t, uint8_t, uint8_t>;

ip_t parse_ip(const std::string& str)
{
    auto parts = split(str, '.');   // ["1", "2", "3", "4"]
    if (parts.size() != 4)
        throw std::runtime_error("bad IP: " + str);

    return {
        static_cast<uint8_t>(std::stoi(parts[0])),
        static_cast<uint8_t>(std::stoi(parts[1])),
        static_cast<uint8_t>(std::stoi(parts[2])),
        static_cast<uint8_t>(std::stoi(parts[3]))
    };
}

    void ip_print(const ip_t& ip)
    {
        std::cout
            << static_cast<int>(std::get<0>(ip)) << "."
            << static_cast<int>(std::get<1>(ip)) << "."
            << static_cast<int>(std::get<2>(ip)) << "."
            << static_cast<int>(std::get<3>(ip)) << "\n";
    }

int mainn()
{
    using ip_t = std::tuple<uint8_t, uint8_t, uint8_t, uint8_t>;
    try
    {
        std::vector<ip_t> ip_pool;

        for(std::string line; std::getline(std::cin, line);)
        {
                auto fields = split(line, '\t');       
                ip_pool.push_back(parse_ip(fields.at(0))); 
        }

        
    std::sort(ip_pool.begin(), ip_pool.end(),
        [](const auto& a, const auto& b) {
            return a > b; 
        });

        for (auto ip = ip_pool.begin(); ip!=ip_pool.end(); ++ip){
            ip_print(*ip);
        }

        std::cout<<"\n";

        for (auto ip = ip_pool.begin(); ip!=ip_pool.end(); ++ip){
            if (std::get<0>(*ip)== 1){
            ip_print(*ip);
            }
        }

        std::cout<<"\n";

        for (auto ip = ip_pool.begin(); ip!=ip_pool.end(); ++ip){
            if (std::get<0>(*ip)== 46 && std::get<1>(*ip)== 70){
            ip_print(*ip);
            }
        }

        std::cout<<"\n";

        for (auto ip = ip_pool.begin(); ip!=ip_pool.end(); ++ip){
            auto [a,b,c,d] = *ip;
            if (a== 46 || b== 46 || c== 46 || d== 46){
            ip_print(*ip);
            }
        }        

    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}

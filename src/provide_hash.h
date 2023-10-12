//
// Created by shecannotsee on 23-10-12.
//

#ifndef SHE_INI_PARSE_PROVIDE_HASH_H
#define SHE_INI_PARSE_PROVIDE_HASH_H

#include <tuple>

// Provide custom hashes to <>
namespace std {
template<>
struct hash<std::tuple<int, int>> {
  std::size_t operator()(const std::tuple<int, int> &key) const {
    using std::hash;
    // Combine the hash values of the two enum values to create a unique hash
    return hash<int>()(static_cast<int>(std::get<0>(key))) ^ hash<int>()(static_cast<int>(std::get<1>(key)));
  }
};
}// namespace std

#endif //SHE_INI_PARSE_PROVIDE_HASH_H

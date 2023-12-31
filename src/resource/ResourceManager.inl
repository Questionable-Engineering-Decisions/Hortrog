#pragma once

#include "ResourceManager.h"

#include <memory>
#include <utility>

template <typename Res, typename Id>
template <typename... Args>
inline bool ResourceManager<Res, Id>::load(const Id& id, Args&&... args) {
    if (map_.contains(id)) return false;
    std::unique_ptr<Res> ptr(new Res);
    if (!ptr->loadFromFile(std::forward<Args>(args)...)) {
        return false;
    }
    map_.emplace(id, std::move(ptr));
    return true;
}

template <typename Res, typename Id>
inline Res* ResourceManager<Res, Id>::get(const Id& id) const {
    auto it = map_.find(id);
    if (it == map_.end()) return nullptr;
    return it->second.get();
}

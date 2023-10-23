#pragma once

#include "gui/View.h"

#include <memory>
#include <unordered_map>

#include "SFML/Graphics/Texture.hpp"

class AssetLoader {
public:
    static AssetLoader& instance();

    const sf::Texture* loadTexture(const std::string& path);
    gui::View* loadView(const std::string& path);

protected:
    AssetLoader() = default;
    AssetLoader(AssetLoader&) = delete;
    AssetLoader(AssetLoader&&) = delete;

private:
    std::unordered_map<std::string, sf::Texture> textures_;
    std::unordered_map<std::string, std::unique_ptr<gui::View>> views_;
};
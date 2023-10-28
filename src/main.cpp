#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "gui/Drawable.h"
#include "multiply/multiply.h"
#include <fstream>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

#include "menu/Menu.h"
#include "SFML/Graphics.hpp"
#include "nlohmann/json.hpp"

using json = nlohmann::json;

class MyRectangle : gui::Drawable {
public:
    MyRectangle(sf::RectangleShape& rect) : rect(rect) {}
    gui::Rect getBoundingBox() const override { return rect.getGlobalBounds(); }
    void draw(gui::Target& target) const override { target.draw(rect); }

private:
    sf::RectangleShape rect;
};

void readAssetFile(const std::string& path) {
    std::ifstream file("assets/" + path);
    if (!file.is_open()) {
        std::cout << "Cannot open asset" << std::endl;
        return;
    }
    json data = json::parse(file);

    std::cout << data["name"].get<std::string>() << std::endl;
    std::cout << data["age"].get<int>() << std::endl;
}

int main() {
    // std::cout << "COS 214 - Final Project" << std::endl;
    // std::cout << "7 * 6 = " << multiply(7, 6) << std::endl;
    // readAssetFile("demo_asset.json");
    // sf::RenderWindow w(sf::VideoMode(800, 600), "COS 214 Final Project");

    // sf::RectangleShape r({300, 200});
    // r.setPosition({10, 10});
    // r.setFillColor(sf::Color(255, 0, 0));
    // MyRectangle rect(r);
    // while (w.isOpen()) {
    //     sf::Event event;
    //     while (w.pollEvent(event)) {
    //         if (event.type == sf::Event::Closed) {
    //             w.close();
    //         }
    //     }
    //     rect.draw(w);
    //     w.display();
    //     // rect.draw(w);
    // }
	Menu * m = new Menu();
	m->initMenu();
	std::string s = m->toString();
	Item item = m->getItem("Lemonade");

	std::cout << s << std::endl;
	std::cout << item.getName() << std::endl;

	return 0;
}
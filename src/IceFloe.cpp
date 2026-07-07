// Player code
#include "IceFloe.h"

IceFloe::IceFloe(Coordinates screen_size) : bar_width(screen_size.x * 1 / 10), bar_height(3), isOriginal(true), screen_size_(screen_size)
{

    // top_bar.setSize(sf::Vector2f(bar_width, bar_height));
    // top_bar.setFillColor(sf::Color(89, 164, 240)); // light blue
    
    // second_layer.setSize(sf::Vector2f(bar_width, bar_height));
    // second_layer.setFillColor(sf::Color(89, 164, 240)); // light blue

    // third_layer.setSize(sf::Vector2f(bar_width, bar_height));
    // third_layer.setFillColor(sf::Color(89, 164, 240)); // light blue

    // fourth_layer.setSize(sf::Vector2f(bar_width, bar_height));
    // fourth_layer.setFillColor(sf::Color(89, 164, 240)); // light blue

    // fifth_layer.setSize(sf::Vector2f(bar_width, bar_height));
    // fifth_layer.setFillColor(sf::Color(89, 164, 240)); // light blue

    // sixth_layer.setSize(sf::Vector2f(bar_width, bar_height));
    // sixth_layer.setFillColor(sf::Color(89, 164, 240)); // light blue
    
    // seventh_layer.setSize(sf::Vector2f(bar_width, bar_height));
    // seventh_layer.setFillColor(sf::Color(89, 164, 240)); // light blue
    for(auto i = 0u; i < 7; i++){
        sf::RectangleShape bar;
        bar.setSize(sf::Vector2f(bar_width, bar_height));
        bar.setFillColor(sf::Color(89, 164, 240)); 
        layers.push_back(bar);
    }
    ResetPosition();
}

void IceFloe::ResetPosition(){
    // std::cout
    //     << "Size: " << screen_size_.x << ", " << screen_size_.y
    //     << std::endl;
    auto height = screen_size_.y - screen_size_.y * 19 / 40 + screen_size_.y * 1 / 50;
    height += 25;
    // layers[0].setPosition(sf::Vector2f(bar_width, height));
    // height += bar_height;
    // layers[1].setPosition(sf::Vector2f(bar_width - bar_height * 2, height));
    // height += bar_height;
    // layers[2].setPosition(sf::Vector2f(bar_width - (bar_height * 2 + bar_height / 2), height));
    // height += bar_height;
    // layers[3].setPosition(sf::Vector2f(bar_width - (bar_height * 4 + bar_height / 2), height));
    // height += bar_height;
    // layers[4].setPosition(sf::Vector2f(bar_width - (bar_height * 4 - bar_height / 3), height));
    // height += bar_height;
    // layers[5].setPosition(sf::Vector2f(bar_width - (bar_height * 4 + bar_height * 3 / 2), height));
    // height += bar_height;
    // layers[6].setPosition(sf::Vector2f(bar_width - (bar_height * 4 + bar_height * 5), height));

    float horizontal_offsets[7] = {
        0.0f,                                            // top_bar
        - (bar_height * 2.0f),                           // second_layer
        - (bar_height * 2.0f + bar_height / 2.0f),       // third_layer
        - (bar_height * 4.0f + bar_height / 2.0f),       // fourth_layer
        - (bar_height * 4.0f - bar_height / 3.0f),       // fifth_layer
        - (bar_height * 4.0f + bar_height * 3.0f / 2.0f),// sixth_layer
        - (bar_height * 4.0f + bar_height * 5.0f)        // seventh_layer
    };

    // Loop through your vector and update each layer's position dynamically
    for(size_t i = 0; i < layers.size(); i++) {
        layers[i].setPosition(sf::Vector2f(bar_width + horizontal_offsets[i], height));
        height += bar_height;
        // std::cout << layers[i].getPosition().x << " " << layers[i].getPosition().y << std::endl;
    }
    
}

void IceFloe::Display(sf::RenderWindow *window)
{
    // window->draw(top_bar);
    // window->draw(second_layer);
    // window->draw(third_layer);
    // window->draw(fourth_layer);
    // window->draw(fifth_layer);
    // window->draw(sixth_layer);
    // window->draw(seventh_layer);
    for(size_t i = 0; i < layers.size(); i++) {
        window->draw(layers[i]);
    }
}

void IceFloe::FlipColor()
{
    if (isOriginal)
    {
        // top_bar.setFillColor(sf::Color::White);
        // second_layer.setFillColor(sf::Color::White);
        // third_layer.setFillColor(sf::Color::White);
        // fourth_layer.setFillColor(sf::Color::White);
        // fifth_layer.setFillColor(sf::Color::White);
        // sixth_layer.setFillColor(sf::Color::White);
        // seventh_layer.setFillColor(sf::Color::White);
        for(size_t i = 0; i < layers.size(); i++) {
            layers[i].setFillColor(sf::Color::White);
        }
    }
    else
    {
        // top_bar.setFillColor(sf::Color(89, 164, 240));
        // second_layer.setFillColor(sf::Color(89, 164, 240));
        // third_layer.setFillColor(sf::Color(89, 164, 240));
        // fourth_layer.setFillColor(sf::Color(89, 164, 240));
        // fifth_layer.setFillColor(sf::Color(89, 164, 240));
        // sixth_layer.setFillColor(sf::Color(89, 164, 240));
        // seventh_layer.setFillColor(sf::Color(89, 164, 240));
        for(size_t i = 0; i < layers.size(); i++) {
            layers[i].setFillColor(sf::Color(89, 164, 240));
        }
    }
    isOriginal = !isOriginal;
}

void IceFloe::AdjustPosition(Coordinates adjust_by)
{
    // auto current_pos = top_bar.getPosition();
    // top_bar.setPosition(sf::Vector2f(adjust_by.x + current_pos.x, adjust_by.y + current_pos.y));

    // current_pos = second_layer.getPosition();
    // second_layer.setPosition(sf::Vector2f(adjust_by.x + current_pos.x, adjust_by.y + current_pos.y));

    // current_pos = third_layer.getPosition();
    // third_layer.setPosition(sf::Vector2f(adjust_by.x + current_pos.x, adjust_by.y + current_pos.y));

    // current_pos = fourth_layer.getPosition();
    // fourth_layer.setPosition(sf::Vector2f(adjust_by.x + current_pos.x, adjust_by.y + current_pos.y));

    // current_pos = fifth_layer.getPosition();
    // fifth_layer.setPosition(sf::Vector2f(adjust_by.x + current_pos.x, adjust_by.y + current_pos.y));

    // current_pos = sixth_layer.getPosition();
    // sixth_layer.setPosition(sf::Vector2f(adjust_by.x + current_pos.x, adjust_by.y + current_pos.y));

    // current_pos = seventh_layer.getPosition();
    // seventh_layer.setPosition(sf::Vector2f(adjust_by.x + current_pos.x, adjust_by.y + current_pos.y));
    // for(size_t i = 0; i < layers.size(); i++) {
    //     auto current_pos = layers[i].getPosition();
    //     layers[i].setPosition(sf::Vector2f(adjust_by.x + current_pos.x, adjust_by.y + current_pos.y));
    // }
    for (auto& layer : layers)
    {
        layer.move(sf::Vector2f(adjust_by.x, adjust_by.y));
    }
}

void IceFloe::UpdatePosition(Coordinates new_position)
{
    // auto current_pos = layers[0].getPosition();
    // layers[0].setPosition(sf::Vector2f(new_position.x + bar_height * 2, current_pos.y));

    // current_pos = layers[1].getPosition();
    // layers[1].setPosition(sf::Vector2f(new_position.x, current_pos.y));

    // current_pos = layers[2].getPosition();
    // layers[2].setPosition(sf::Vector2f(new_position.x - (bar_height / 2), current_pos.y));

    // current_pos = layers[3].getPosition();
    // layers[3].setPosition(sf::Vector2f(new_position.x - (bar_height * 2 + bar_height / 2), current_pos.y));

    // current_pos = layers[4].getPosition();
    // layers[4].setPosition(sf::Vector2f(new_position.x - (bar_height * 2 - bar_height / 3), current_pos.y));

    // current_pos = layers[5].getPosition();
    // layers[5].setPosition(sf::Vector2f(new_position.x - (bar_height * 2 + bar_height * 3 / 2), current_pos.y));

    // current_pos = layers[6].getPosition();
    // layers[6].setPosition(sf::Vector2f(new_position.x - (bar_height * 2 + bar_height * 5), current_pos.y));
    // ResetPosition();
    // AdjustPosition(new_position);
    const float horizontalOffsets[7] =
    {
        0.f,
        -(bar_height * 2.f),
        -(bar_height * 2.f + bar_height / 2.f),
        -(bar_height * 4.f + bar_height / 2.f),
        -(bar_height * 4.f - bar_height / 3.f),
        -(bar_height * 4.f + bar_height * 3.f / 2.f),
        -(bar_height * 4.f + bar_height * 5.f)
    };
    for (size_t i = 0; i < layers.size(); ++i)
    {
        auto pos = layers[i].getPosition();
        layers[i].setPosition(
            sf::Vector2f(new_position.x + horizontalOffsets[i],
            pos.y)
        );
    }
}

Coordinates IceFloe::GetSize() const
{
    return Coordinates(bar_width, bar_height);
}

Coordinates IceFloe::GetPosition() const
{
    return Coordinates(layers[1].getPosition().x, layers[1].getPosition().y);
}

bool IceFloe::IsOriginalColor() const
{
    return isOriginal;
}
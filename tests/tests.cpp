#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <IceFloe.h>

/**********
 * Testing the IceFloe Class
 */
TEST_CASE("Constructor sets the properties properlly")
{
    auto screen_size = Coordinates(1000, 600);
    auto ice_floe = IceFloe(screen_size);
    // check size of icefloe not equal zero
    CHECK((ice_floe.GetSize().x != 0 && ice_floe.GetSize().y != 0));
    // check icefloe initially is whithin screen
    CHECK((ice_floe.GetPosition().x >= 0 && ice_floe.GetPosition().y >= 0));
    CHECK((ice_floe.GetPosition().x <= screen_size.x && ice_floe.GetPosition().y <= screen_size.y));
}

TEST_CASE("Test adjusting the position of ice floe")
{
    auto screen_size = Coordinates(1000, 600);
    auto ice_floe = IceFloe(screen_size);
    // adding zero doesnt change the current position of the ice floe
    auto current_pos = ice_floe.GetPosition();
    ice_floe.AdjustPosition(Coordinates(0, 0));
    auto new_position = ice_floe.GetPosition();

    CHECK_EQ(current_pos.x, new_position.x);
    CHECK_EQ(current_pos.y, new_position.y);
    // adding a non zero position to the ice floe
    current_pos = ice_floe.GetPosition();
    ice_floe.AdjustPosition(Coordinates(7, 4));
    new_position = ice_floe.GetPosition();
    CHECK_GT(new_position.x, current_pos.x);
    CHECK_GT(new_position.y, current_pos.y);
    // subtracting a non zero position to the ice floe
    current_pos = ice_floe.GetPosition();
    ice_floe.AdjustPosition(Coordinates(-7, -4));
    new_position = ice_floe.GetPosition();
    CHECK_LT(new_position.x, current_pos.x);
    CHECK_LT(new_position.y, current_pos.y);
}

TEST_CASE("Test updating the position of ice floe")
{
    auto screen_size = Coordinates(1000, 600);
    auto ice_floe = IceFloe(screen_size);
    // updating the ice floe doesnt affect the y coordnitates
    auto position = Coordinates(7, 6);
    auto current_pos = ice_floe.GetPosition();
    ice_floe.UpdatePosition(position);
    auto new_position = ice_floe.GetPosition();
    CHECK_EQ(new_position.y, current_pos.y);

    // the x coordinate becomes the new position
    CHECK_EQ(new_position.x, position.x);
}

TEST_CASE("Test flipping the color of ice floe")
{
    auto screen_size = Coordinates(1000, 600);
    auto ice_floe = IceFloe(screen_size);
    auto original_color = ice_floe.IsOriginalColor();
    ice_floe.FlipColor();
    auto flipped_color = ice_floe.IsOriginalColor();
    ice_floe.FlipColor();
    auto new_color = ice_floe.IsOriginalColor();

    CHECK_NE(original_color, flipped_color);
    CHECK_EQ(original_color, new_color);
}

/**********
 * Testing the IceFloeLayer Class
 */

void my_delay(int my_delay)
{
    sf::Clock zegar;
    sf::Time czas;
    while (1)
    {
        czas = zegar.getElapsedTime();
        if (czas.asMilliseconds() > my_delay)
        {
            zegar.restart();
            break;
        }
    }
}
# Boron
Boron is a personal little game engine, mostly written to learn more about C++ and game engines in general.

# Creating a game with Boron
The Engine itself gets compiled into a dll, which the game must dynamically link against.
The single point of contact to the engine in the game code is the Boron.h header file, no other includes of engine headers are necessary.

The Base class for the Game must inherit from Boron::Application and implement its abstract methods.
The Game also needs to implement the Boron::CreateApplication() function that constructs and returns an Instance of the Game base class.

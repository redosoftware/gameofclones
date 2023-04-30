# Game 1 - The Oregon Trail (1971)

## Game Research

### Resources

- https://en.wikipedia.org/wiki/The_Oregon_Trail_(1971_video_game)
- https://www.filfre.net/2011/04/on-the-trail-of-the-oregon-trail-part-5/
- https://www.youtube.com/watch?v=NAI8Ysqbq7E

### Features

- Text Based: the player recieves instructions and has a few options to respond with. The input is usually numbers (for the options or to insert currency values)
- Random Events: once in a while a random event that will affect the player's resources will be triggered. They may or may not need input from the player.
- Hunting Minigame: while hunting (or fighting bandits) the player is prompt with an action that requires to type a specific word. The faster the player inputs that word, the better the outcome. Being too slow or writing the wrogn word will produce a negative outcome.

### Basic Game Loop

1. Game intro
2. Initial resources purchase
3. Rounds
    1. Show travel info: date, milage, current resources
    2. Fort (random), purchase supplies.
    3. Hunt desicion (Hunting minigame)
    4. Eat Desicion
    5. Random Event (or none)

Repeats step 3 until journey ends (by reaching Oregon or some horrible outcome)

## Clone Tweaks

### New Story

You are the captain of the spaceship CSS Oregon. Your mission: transport your crew from Earth through the Solar System and arrive safely in Titan's colony. The humans in Jupiter's moon are waiting for new members and medical supplies.

You won't be alone in this dangerous voyage, the spaceship AI SAGAN. (Satelital Galactic Navigator) will help you, sharing all its knowledge of the universe and alerting you about the perils among the stars.

You will count with supplies that you'll need to maintain and manage carefully to avoid any great loses. Your resources are:

* Crypto Units: for pruchasing more supplies or negotiate with space pirates.
* Dark Matter: to feed the ship's engine. The more you have, the faster the ship will go.
* Food: people get hungry, specially in space.
* Energy Catridges: sometimes laser beams are the best way to negotiate.
* Spare Parts: to fix the ship.
* Medical Supplies: to heal your wouded and also to deliver at destination.

### Other changes
* Instead of hunting animals, it will be necessary to colect dark matter to fuel the engine. There will be three random words that might come up: ZAP, BLEEP, BLOOP.
* I may add the chance to sell stuff in the forts
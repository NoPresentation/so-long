*This project has been created as part of the 42 curriculum by anashwan.*

# so_long

## Description

`so_long` is a simple 2D game where the player navigates a map, collects items, and reaches an exit. The main goal of the project is to understand and implement:

- Map parsing and validation.
- Dealing with 2D arrays and map constraints.
- Pathfinding and game logic.
- Handling player input and movement.
- Understanding what a graphics server is.
- Graphics rendering using the MinilibX library.

Map structure:
```
1: Wall
0: Ground
P: Player
E: Exit
C: Collectible
```
Map rules:

1. Must be rectangular.
2. Must be surrounded by walls.
3. Must have at least one collectible.
4. Must have a valid path from the player to the collectibles and exit.
5. Must be `.ber` in format.

Example of a valid map:
```
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
```

---

## Instructions

### Compilation

```bash
make
```

This will compile the necessary files and build the dependencies and the game.

To play the game, run:

```bash
./so_long ./maps/map.ber
```

To remove game files you can use:

```bash
make fclean # removes the game
make clean # keeps the game but removes the dependencies
```

Enjoy :D

## Resources
[MinilibX Documentation](https://harm-smits.github.io/42docs/libs/minilibx)

[Floodfill algorithm Youtube guide](https://youtu.be/VuiXOc81UDM)

## AI usage
AI was mainly used as a debugging tool, it also helped me style my code according to the 42 Norminette.
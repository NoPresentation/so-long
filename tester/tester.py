import subprocess
import os

# absolute path to THIS script's directory
SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))

# absolute path to so_long binary (one level above tester/)
SO_LONG = os.path.join(SCRIPT_DIR, "..", "so_long")

# absolute path to test_maps/
MAP_DIR = os.path.join(SCRIPT_DIR, "test_maps")

maps = [
    "invalid_contains_strange_character.ber",
    "invalid_empty.ber",
    "invalid_more_than_one_exit.ber",
    "invalid_more_than_one_player.ber",
    "invalid_no_collectibles.ber",
    "invalid_no_exit.ber",
    "invalid_no_player.ber",
    "invalid_not_rectangular.ber",
    "invalid_not_surrounded_by_wall.ber",
    "invalid_not_surrounded_by_wall1.ber",
    "invalid_path.txt",
    "invalid_path_to_collectible.ber",
    "invalid_path_to_collectible1.ber",
    "invalid_path_to_collectible2.ber",
    "invalid_path_to_collectible3.ber",
    "invalid_path_to_exit_and_colletibles.ber",
    "invalid_stupid_input.ber",
]

# sanity checks (fail fast, no mystery)
if not os.path.exists(SO_LONG):
    print("❌ so_long binary not found:", SO_LONG)
    exit(1)

for m in maps:
    map_path = os.path.join(MAP_DIR, m)
    if not os.path.exists(map_path):
        print("❌ map not found:", map_path)
        exit(1)

# run valgrind
for m in maps:
    map_path = os.path.join(MAP_DIR, m)

    print("\n" + "=" * 60)
    print(f"valgrind {SO_LONG} {map_path}")
    print("=" * 60)

    subprocess.run([
        "valgrind",
        SO_LONG,
        map_path
    ])

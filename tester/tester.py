import subprocess
import re

def parse_leaks(stderr):
    leaks = {
        "definitely": 0,
        "indirectly": 0,
        "possibly": 0,
        "reachable": 0,
    }

    patterns = {
        "definitely": r"definitely lost:\s+(\d+)",
        "indirectly": r"indirectly lost:\s+(\d+)",
        "possibly": r"possibly lost:\s+(\d+)",
        "reachable": r"still reachable:\s+(\d+)",
    }

    for key, pattern in patterns.items():
        match = re.search(pattern, stderr)
        if match:
            leaks[key] = int(match.group(1))

    return leaks

def main():
    map_list = [
        "2.ber",
        "3.ber",
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
        "map.ber",
        "map1.ber",
        "map2.ber",
        "map3.ber",
        "map4.ber",
        "map5.ber",
    ]

    for m in map_list:
        print(f"\n=== Testing {m} ===")

        result = subprocess.run(
            ["valgrind", "--leak-check=full", "./so_long", m],
            capture_output=True,
            text=True
        )

        leaks = parse_leaks(result.stderr)

        print(f"definitely lost : {leaks['definitely']}")
        print(f"indirectly lost : {leaks['indirectly']}")
        print(f"possibly lost   : {leaks['possibly']}")
        print(f"reachable       : {leaks['reachable']}")

        if any(leaks.values()):
            print("❌ LEAKS DETECTED")
        else:
            print("✅ NO LEAKS")

if __name__ == "__main__":
    main()

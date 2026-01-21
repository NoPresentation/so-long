import subprocess

def main():
    map_list = [
        "2.ber"
        "3.ber"
        "invalid_contains_strange_character.ber"
        "invalid_empty.ber"
        "invalid_more_than_one_exit.ber"
        "invalid_more_than_one_player.ber"
        "invalid_no_collectibles.ber"
        "invalid_no_exit.ber"
        "invalid_no_player.ber"
        "invalid_not_rectangular.ber"
        "invalid_not_surrounded_by_wall.ber"
        "invalid_not_surrounded_by_wall1.ber"
        "invalid_path.txt"
        "invalid_path_to_collectible.ber"
        "invalid_path_to_collectible1.ber"
        "invalid_path_to_collectible2.ber"
        "invalid_path_to_collectible3.ber"
        "invalid_path_to_exit_and_colletibles.ber"
        "invalid_stupid_input.ber"
        "map.ber"
        "map1.ber"
        "map2.ber"
        "map3.ber"
        "map4.ber"
        "map5.ber"
    ]

    for m in map_list:
        command = f"valgrind ./so_7long {m}"
        valgrind = subprocess.run(command, capture_output=True, text=True)
        definetely = subprocess.run(['grep', 'definitely'], capture_output=True, text=True, stdin=valgrind.stderr)
        indirectly = subprocess.run(['grep', 'indirectly'], capture_output=True, text=True, stdin=valgrind.stderr)
        possibly = subprocess.run(['grep', 'possibly '], capture_output=True, text=True, stdin=valgrind.stderr)
        reachable = subprocess.run(['grep', 'reachable'], capture_output=True, text=True, stdin=valgrind.stderr)

        d_lost = int(definetely.stdout.split(':')[1].strip().split(' ')[0])
        p_lost = int(possibly.stdout.split(':')[1].strip().split(' ')[0])
        i_lost = int(indirectly.stdout.split(':')[1].strip().split(' ')[0])
        r_lost = int(reachable.stdout.split(':')[1].strip().split(' ')[0])




bool is_thirteen_orphans(const map<int, int>& tiles)
{
    for (auto& kv : tiles) {
        if (!is_orphans(kv.first)) {
            return false;
        }
    }
    return tiles.size() == 13;
}

bool is_seven_pairs(const map<int, int>& tiles)
{
    for (auto& kv : tiles) {
        if (kv.second % 2) {
            return false;
        }
    }
    return true;
}

int map_sum(const map<int, int>& tiles)
{
    int sum = 0;
    for (auto& kv : tiles) {
        sum += kv.second;
    }
    return sum;
}

bool is_hu(const map<int, int>& tiles)
{
    int tile_count = map_sum(tiles);
    if (tile_count == 14) {
        if (is_thirteen_orphans(tiles) || is_seven_pairs(tiles)) {
            return true;
        }
    }
    if (tile_count == 2 && tiles.size() == 1) {
        return true;
    }
    for (auto& kv : tiles) {
        int tile_id = kv.first;
        if (kv.second >= 3) {
            map<int, int> clone(tiles);
            modify_map(clone, tile_id, -3);
            if (is_hu(clone)) {
                return true;
            }
        }
        if (!is_word(tile_id) && tile_id % 9 <= 6) {
            if (tiles.count(tile_id + 1) && tiles.count(tile_id + 2)) {
                map<int, int> clone(tiles);
                modify_map(clone, tile_id, -1);
                modify_map(clone, tile_id + 1, -1);
                modify_map(clone, tile_id + 2, -1);
                if (is_hu(clone)) {
                    return true;
                }
            }
        }
    }

    return false;
}

bool is_hu(int tile_id)
{
    map<int, int> clone(hand);
    if (tile_id >= 0) {
        modify_map(clone, tile_id, 1);
    }
    return is_hu(clone);
}

void out()
{
    if (is_hu(-1)) {
        cout << "hu" << endl;
        return;
    }
    int tile_id = hand.cbegin()->first;
    cout << "out " << id_to_tile(tile_id) << endl;
    modify_hand(tile_id, -1);
}

void declare(int tile_id)
{
    cout << "pass" << endl;
}

void qgang(int tile_id)
{
    if (is_hu(tile_id)) {
        cout << "qgang" << endl;
    }
    else {
        cout << "pass" << endl;
    }
}
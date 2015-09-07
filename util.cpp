const vector<char> word_tiles{ 'E', 'S', 'W', 'N', 'Z', 'F', 'B' };
const vector<char> colors{ 'M', 'T', 'S' };
const vector<string> all_tiles{
    "1M", "2M", "3M", "4M", "5M", "6M", "7M", "8M", "9M",
    "1T", "2T", "3T", "4T", "5T", "6T", "7T", "8T", "9T",
    "1S", "2S", "3S", "4S", "5S", "6S", "7S", "8S", "9S",
    "E", "S", "W", "N", "Z", "F", "B"
};

int tile_to_id(const string& tile)
{
    if (tile.size() == 1) {
        auto result = find(begin(word_tiles), end(word_tiles), tile[0]);
        return result - begin(word_tiles) + 27;
    }
    auto result = find(begin(colors), end(colors), tile[1]);
    int color = result - begin(colors);
    int num = tile[0] - '0';
    return color * 9 + num - 1;
}

string id_to_tile(int id)
{
    return all_tiles[id];
}

bool is_word(int id)
{
    return id >= 27;
}

bool is_orphans(int tile_id)
{
    if (tile_id >= 26) {
        return true;
    }
    int num = tile_id % 9;
    if (num == 0 || num == 8) {
        return true;
    }
    return false;
}

void modify_map(map<int, int>& m, int tile_id, int delta)
{
    int val = (m[tile_id] += delta);
    if (val == 0) {
        m.erase(m.find(tile_id));
    }
}

void modify_hand(int tile_id, int delta)
{
    modify_map(hand, tile_id, delta);
}
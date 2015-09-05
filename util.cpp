const vector<char> word_tiles{ 'E', 'S', 'W', 'N', 'Z', 'F', 'B' };
const vector<char> colors{ 'M', 'T', 'S' };
const vector<string> all_tiles{ "1M", "2M", "3M", "4M", "5M", "6M", "7M", "8M", "9M", "1S", "2S", "3S", "4S", "5S",
    "6S", "7S", "8S", "9S", "1T", "2T", "3T", "4T", "5T", "6T", "7T", "8T", "9T", "E", "S",
    "W", "N", "Z", "F", "B" };

int tile_to_id(const string& tile)
{
    if (tile.size() == 1) {
        auto result = find(begin(word_tiles), end(word_tiles), tile[0]);
        return result - begin(word_tiles) + 27;
    }
    auto result = find(begin(word_tiles), end(word_tiles), tile[1]);
    int color = result - begin(word_tiles);
    int num = tile[0] - '0';
    return color * 9 + num - 1;
}

string id_to_tile(int id)
{
    return all_tiles[id];
}
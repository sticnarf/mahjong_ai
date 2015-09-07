void pick()
{
    string tile;
    cin >> tile;
    int tile_id = tile_to_id(tile);
    remain[tile_id] -= 1;
    modify_hand(tile_id, 1);
    out();
}

void mpick()
{
    int id;
    cin >> id;
}

void mout()
{
    int id;
    string tile;
    cin >> id >> tile;
    int tile_id = tile_to_id(tile);
    remain[tile_id] -= 1;
    last_tile = tile_id;
    declare(tile_id);
}

void mpeng()
{
    int id;
    string tile;
    cin >> id >> tile;
    int tile_id = tile_to_id(tile);
    remain[tile_id] -= 3;
    if (id == self) {
        modify_hand(tile_id, -2);
    }
}

void mfail()
{
}

void mchi()
{
    int id;
    string tile;
    cin >> id >> tile;
    int tile_id = tile_to_id(tile);
    remain[tile_id] -= 1;
    remain[tile_id + 1] -= 1;
    remain[tile_id + 2] -= 1;
    if (id == self) {
        modify_hand(last_tile, 1);
        modify_hand(tile_id, -1);
        modify_hand(tile_id + 1, -1);
        modify_hand(tile_id + 2, -1);
    }
}

void mgang()
{
    int id;
    string tile;
    cin >> id >> tile;
    int tile_id = tile_to_id(tile);
    remain[tile_id] -= 4;
    if (id == self) {
        modify_hand(tile_id, -3);
    }
}

void magang()
{
    int id;
    cin >> id;
    if (id == self) {
        modify_hand(last_tile, -4);
    }
}

void mjgang()
{
    int id;
    string tile;
    cin >> id >> tile;
    int tile_id = tile_to_id(tile);
    remain[tile_id] -= 1;
    qgang(tile_id);
}

map<string, function<void()> > functions = {
    { "pick", pick }, { "mpick", mpick }, { "mout", mout }, { "mpeng", mpeng },
    { "mfail", mfail }, { "mchi", mchi }, { "mgang", mgang }, { "magang", magang }, { "mjgang", mjgang }
};
bool is_hu(int tile_id)
{
    return false;
}

void out()
{
    if (is_hu(-1)) {
        cout << "hu" << endl;
        return;
    }
    cout << "out " << id_to_tile(*hand.begin()) << endl;
    hand.erase(hand.begin());
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
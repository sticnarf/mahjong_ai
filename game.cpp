void join()
{
    string _;
    cout << "join" << endl;
    cin >> _ >> self;
    cin >> _ >> first;
}

void init()
{
    for (int i = 0; i < 34; i++) {
        remain[i] = 4;
    }
    
    string _;
    cin >> _;
    for (int i = 0; i < 13; i++) {
        string tile;
        cin >> tile;
        int tile_id = tile_to_id(tile);
        hand[tile_id] += 1;
        remain[tile_id] -= 1;
    }
}

void loop()
{
    for (;;) {
        string type;
        cin >> type;
        auto func = functions[type];
        func();
    }
}

void start()
{
    join();
    init();
    loop();
}
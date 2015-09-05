void pick()
{
    string tile;
    cin >> tile;
    cout << "out " << tile << endl;
}

void mpick()
{
    string tile;
    cin >> tile;
}

void mout()
{
    int id;
    string tile;
    cin >> id >> tile;
    cout << "pass" << endl;
}

void mpeng()
{
    int id;
    string tile;
    cin >> id >> tile;
}

void mfail()
{
}

void mchi()
{
    int id;
    string tile;
    cin >> id >> tile;
}

void mgang()
{
    int id;
    string tile;
    cin >> id >> tile;
}

void magang()
{
    int id;
    cin >> id;
}

void mjgang()
{
    int id;
    string tile;
    cin >> id >> tile;
    cout << "pass" << endl;
}

unordered_map<string, function<void()> > functions = {
    { "pick", pick }, { "mpick", mpick }, { "mout", mout }, { "mpeng", mpeng },
    { "mfail", mfail }, { "mchi", mchi }, { "mgang", mgang }, { "magang", magang }, { "mjgang", mjgang }
};
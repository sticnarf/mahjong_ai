#[macro_use]
extern crate scan_fmt;
use std::io;

fn main() {
    let mut game = Game {
        id: 0,
        first: 0,
        tiles: Vec::new()
    };
    game.run();
}

struct Game {
    id: u32,
    first: u32,
    tiles: Vec<String>
}

impl Game {
    fn run(&mut self) {
        println!("join");
        self.id = scanln_fmt!("id {}", u32).unwrap();
        self.first = scanln_fmt!("first {}", u32).unwrap();
        let mut line = String::new();
        io::stdin().read_line(&mut line).ok();
        let v: Vec<_> = line.trim().split(' ').collect();
        for i in 1..14 {
            self.tiles.push(v[i].to_string());
        }
        loop {
            let mut line = String::new();
            io::stdin().read_line(&mut line).ok();
            let line = line.trim();
            match line.split(' ').next().unwrap() {
                "pick" => {
                    let tile = scan_fmt!(line, "pick {}", String);
                    self.pick(tile.unwrap());
                },
                "mpick" => {
                    let id = scan_fmt!(line, "mpick {}", u32);
                    self.mpick(id.unwrap());
                },
                "mout" => {
                    let (id, tile) = scan_fmt!(line, "mout {} {}", u32, String);
                    self.mout(id.unwrap(), tile.unwrap());
                },
                "mpeng" => {
                    let (id, tile) = scan_fmt!(line, "mpeng {} {}", u32, String);
                    self.mpeng(id.unwrap(), tile.unwrap());
                },
                "mfail" => {
                    self.mfail();
                },
                "mchi" => {
                    let (id, tile) = scan_fmt!(line, "mchi {} {}", u32, String);
                    self.mchi(id.unwrap(), tile.unwrap());
                },
                "mgang" => {
                    let (id, tile) = scan_fmt!(line, "mgang {} {}", u32, String);
                    self.mgang(id.unwrap(), tile.unwrap());
                },
                "magang" => {
                    let id = scan_fmt!(line, "magang {}", u32);
                    self.magang(id.unwrap());
                },
                "mjgang" => {
                    let (id, tile) = scan_fmt!(line, "mjgang {} {}", u32, String);
                    self.mjgang(id.unwrap(), tile.unwrap());
                },
                _ => ()
            }
        }
    }

    fn pick(&mut self, tile: String) {
        // TODO
        println!("out {}", tile);
    }

    fn mpick(&mut self, id: u32) {
        // TODO
    }

    fn mout(&mut self, id: u32, tile: String) {
        // TODO
        println!("pass");
    }

    fn mpeng(&mut self, id: u32, tile: String) {
        // TODO
    }

    fn mfail(&mut self) {
        // TODO
    }

    fn mchi(&mut self, id: u32, tile: String) {
        // TODO
    }

    fn mgang(&mut self, id: u32, tile: String) {
        // TODO
    }

    fn magang(&mut self, id: u32) {
        // TODO
    }

    fn mjgang(&mut self, id: u32, tile: String) {
        // TODO
    }
}
// text.cpp
// Erroll Abrahamian
// 12-20-2018

#include <iostream>
#include <string>
#include <cctype>
#include <thread>
using namespace std;

/*
pool = 0
lobby = 1
parking = 2, 3
bridge = 4
street = 5, 6, 7
home = 8
            POOL
            LBY
      PLA   PLB
BRD   ST0   ST1   ST2   HOME

pick up keys in the lobby, go to Parking Lot A to get the car, then go home
*/

enum Rooms_Enum {POOL, LOBBY, PARKINGLOT0, PARKINGLOT1, BRIDGE, STREET0, STREET1, STREET2, HOME};

enum Dirs_Enum {N, S, E, W};

enum Mons_Enum {DINOSAUR, ZOMBIE, HAPPYFACE, XENOMORPH};

// use sentinel if we don't have an exit from a room, kept separate from Rooms_Enum
const int NONE = -1;

// number of rooms
const int ROOMS = 9;

// number of potential exit directions
const int EXITS = 4;

// number of potential monsters
const int MONS = 4;

struct Rooms
{
  string title,
    desc,
    look;
  bool flag,
    visited,
    monster;
  int exit[EXITS];
} room[ROOMS];

struct Directions
{
  char compass;
  int dirNum;
} dirs[EXITS];

struct Monsters
{
  string name,
    ability,
    art,
    win,
    check;
  char winKey;
  bool fought;
} monst[MONS];

class GetHome
{
private:
  // current room, based on room number and Rooms_Enum
  int curRoom;

  // booleans for having keys and car
  //bool hasKeys = false,
    //hasCar = false,

    // winner for, well, yeah
  bool winner = false;

  // input for movement
  char move,

    // input to quit
    forSure;

  string playerName;

public:
  // function prototypes
  void setRooms(Rooms *rm);
  void setDirs(Directions *dir);
  void setMons(Monsters *mon);
  void sayHi();
  void gameMenu();
  void getName();
  void play(Rooms *rm, Monsters *mon);
  char getMove();
  void fightMonster(Rooms *rm, Monsters *mon);
  bool playRoom(char move, Rooms *rm, Directions *dir);
  bool makeMove(Rooms *rm, Directions *dir);
  bool checkWin(Rooms *rm);
  bool checkQuit();
  void printMeal();
};

int main()
{
  GetHome game;

  // random seed for monster usage
  srand(time(0));

  // establish the layout of the rooms and exit directions
  game.setRooms(room);
  game.setDirs(dirs);
  game.setMons(monst);
  game.sayHi();
  this_thread::sleep_for(1500ms);
  game.gameMenu();
  this_thread::sleep_for(1500ms);
  game.getName();
  game.play(room, monst);
}

void GetHome::setRooms(Rooms *rm)
{
  rm[POOL].title = "Swimming Pool";
  rm[POOL].desc = "You are floating in a swimming pool.\nThere is an exit to the south, but something doesn't feel right.\nIs there something in the water with you?\n";
  rm[POOL].look = "\nYou are floating in the swimming pool. Still.\nThere is an exit to the south.\n";
  rm[POOL].flag = true;
  rm[POOL].visited = true;
  rm[POOL].monster = true;
  rm[POOL].exit[N] = NONE;
  rm[POOL].exit[S] = LOBBY;
  rm[POOL].exit[E] = NONE;
  rm[POOL].exit[W] = NONE;

  rm[LOBBY].title = "Lobby";
  rm[LOBBY].desc = "You are in a hotel lobby. Did you stay here last night? It's all such a blur.\nYou see your car (k)eys on the ground. Weird.\nNow, where did you park?\nOh, there's a parking lot to the south.\n";
  rm[LOBBY].look = "\nYou are in the hotel lobby.\nThe swimming pool is to the north.\nThe parking lot is to the south.\n";
  rm[LOBBY].flag = false;
  rm[LOBBY].visited = false;
  rm[LOBBY].monster = false;
  rm[LOBBY].exit[N] = POOL;
  rm[LOBBY].exit[S] = PARKINGLOT1;
  rm[LOBBY].exit[E] = NONE;
  rm[LOBBY].exit[W] = NONE;

  rm[PARKINGLOT0].title = "Parking Lot A";
  rm[PARKINGLOT0].desc = "You're in Parking Lot A.\nParking Lot B is to the east, and the rest is fenced.\nThat (c)ar over there looks familiar, though...\n";
  rm[PARKINGLOT0].look = "\nYou're in Parking Lot A.\nParking Lot B is to the east, and the rest is fenced.\n";
  rm[PARKINGLOT0].flag = false;
  rm[PARKINGLOT0].visited = false;
  rm[PARKINGLOT0].monster = false;
  rm[PARKINGLOT0].exit[N] = NONE;
  rm[PARKINGLOT0].exit[S] = NONE;
  rm[PARKINGLOT0].exit[E] = PARKINGLOT1;
  rm[PARKINGLOT0].exit[W] = NONE;

  rm[PARKINGLOT1].title = "Parking Lot B";
  rm[PARKINGLOT1].desc = "You're in Parking Lot B.\nTo the north is the lobby.\nTo the south is the street.\nTo the east is the parking lot fence.\nTo the west is Parking Lot A.\n";
  rm[PARKINGLOT1].look = "\nYou're in Parking Lot B.\nTo the north is the lobby.\nTo the south is the street.\nTo the east is the parking lot fence.\nTo the west is Parking Lot A.\n";
  rm[PARKINGLOT1].flag = true;
  rm[PARKINGLOT1].visited = false;
  rm[PARKINGLOT1].monster = false;
  rm[PARKINGLOT1].exit[N] = LOBBY;
  rm[PARKINGLOT1].exit[S] = STREET1;
  rm[PARKINGLOT1].exit[E] = NONE;
  rm[PARKINGLOT1].exit[W] = PARKINGLOT0;

  rm[BRIDGE].title = "Collapsed Bridge";
  rm[BRIDGE].desc = "You're at the edge of a collapsed bridge.\nThe only way out is the street to the east, but something's in the rubble...\n";
  rm[BRIDGE].look = "\nYou're at the edge of the collapsed bridge.\n";
  rm[BRIDGE].flag = true;
  rm[BRIDGE].visited = false;
  rm[BRIDGE].monster = true;
  rm[BRIDGE].exit[N] = NONE;
  rm[BRIDGE].exit[S] = NONE;
  rm[BRIDGE].exit[E] = STREET0;
  rm[BRIDGE].exit[W] = NONE;

  rm[STREET0].title = "West Street";
  rm[STREET0].desc = "You're on the western-most part of the street.\nA bridge is to the west.\nThe street continues to the east, but your way is blocked!\n";
  rm[STREET0].look = "\nYou're on the western-most part of the street.\nA bridge is to the west.\nThe street continues to the east.\n";
  rm[STREET0].flag = true;
  rm[STREET0].visited = false;
  rm[STREET0].monster = true;
  rm[STREET0].exit[N] = NONE;
  rm[STREET0].exit[S] = NONE;
  rm[STREET0].exit[E] = STREET1;
  rm[STREET0].exit[W] = BRIDGE;

  rm[STREET1].title = "Mid Street";
  rm[STREET1].desc = "You're on the middle of the street.\nThe street continues to the east and west.\nThe parking lot is to the north.\n";
  rm[STREET1].look = "\nYou're on the middle of the street.\nThe street continues to the east and west.\nThe parking lot is to the north.\n";
  rm[STREET1].flag = true;
  rm[STREET1].visited = false;
  rm[STREET1].monster = false;
  rm[STREET1].exit[N] = PARKINGLOT1;
  rm[STREET1].exit[S] = NONE;
  rm[STREET1].exit[E] = STREET2;
  rm[STREET1].exit[W] = STREET0;

  rm[STREET2].title = "East Street";
  rm[STREET2].desc = "You're on the eastern-most part of the street.\nThe street continues to the west.\nYou see your house to the east! But what's that...\n";
  rm[STREET2].look = "\nYou're on the eastern-most part of the street.\nThe street continues to the west.\nYou see your house to the east.\n";
  rm[STREET2].flag = true;
  rm[STREET2].visited = false;
  rm[STREET2].monster = true;
  rm[STREET2].exit[N] = NONE;
  rm[STREET2].exit[S] = NONE;
  rm[STREET2].exit[E] = HOME;
  rm[STREET2].exit[W] = STREET1;

  rm[HOME].title = "Home";
  rm[HOME].desc = "You're home! But do you have everything?\n";
  rm[HOME].look = "\nYou're home.\n";
  rm[HOME].flag = true;
  rm[HOME].visited = false;
  rm[HOME].monster = false;
  rm[HOME].exit[N] = NONE;
  rm[HOME].exit[S] = NONE;
  rm[HOME].exit[E] = NONE;
  rm[HOME].exit[W] = STREET2;

/* copypaste template
  rm[].title = "";
  rm[].desc = "";
  rm[].look = "";
  rm[].flag = true; // checks for items in certain rooms
  rm[].visited = false;
  rm[].monster = ;
  rm[].exit[N] = ;
  rm[].exit[S] = ;
  rm[].exit[E] = ;
  rm[].exit[W] = ;
*/
}

void GetHome::setDirs(Directions *dir)
{
  // compass is the char variable of the direction
  // dirNum refers to the integer set with Dirs_Enum
  dir[N].compass = 'N';
  dir[N].dirNum = N;
  dir[S].compass = 'S';
  dir[S].dirNum = S;
  dir[E].compass = 'E';
  dir[E].dirNum = E;
  dir[W].compass = 'W';
  dir[W].dirNum = W;
}

void GetHome::setMons(Monsters *mon)
{
  mon[DINOSAUR].name = "Dinosaur";
  mon[DINOSAUR].ability = "\nThis thing is huge! Remember that one movie though?\nSome of the big ones don't see very well. What if you (c)rouched out of sight...\n";
  // mon[DINOSAUR].art = "DINO ART";
  mon[DINOSAUR].art = "                              __\n                             /oo\\\n                            |    |\n                        ^^  (vvvv)   ^^\n                        \\\\  /\\__/\\  //\n                         \\\\/      \\//\n                          /        \\\n                         |          |    ^\n                        /          \\___/ |\n                       (            )     |\n                        \\----------/     /\n                          //    \\\\_____/\n                         W       W\n";
  mon[DINOSAUR].win = "\nYou managed to crouch long enough for the Dinosaur to move along.\nIt's someone else's problem now.\n";
  mon[DINOSAUR].check = "Are you sure you don't want to (c)rouch?\n";
  mon[DINOSAUR].winKey = 'C';
  mon[DINOSAUR].fought = false;

  mon[ZOMBIE].name = "Zombie";
  mon[ZOMBIE].ability = "\nEw. How fast can you (g)et away?\n";
  mon[ZOMBIE].art = "                                 .....\n                                C C  /\n                               /<   /\n                ___ __________/_#__=o\n               /(- /(\\_\\________   \\\n               \\ ) \\ )_      \\o     \\\n               /|\\ /|\\       |'     |\n                             |     _|\n                             /o   __\\\n                            / '     |\n                           / /      |\n                          /_/\\______|\n                         (   _(    <\n                          \\    \\    \\\n                           \\    \\    |\n                            \\____\\____\\\n                            ____\\_\\__\\_\\\n                           /`   /`     o\\\n                          |___ |_______|\n";
  mon[ZOMBIE].win = "\nWow, you got away pretty fast.\n";
  mon[ZOMBIE].check = "Are you sure you don't want to (g)et away?\n";
  mon[ZOMBIE].winKey = 'G';
  mon[ZOMBIE].fought = false;

  mon[HAPPYFACE].name = "Happy Face";
  mon[HAPPYFACE].ability = "\nThis guy isn't even scary. All he wants is to bring (j)oy!\n";
  mon[HAPPYFACE].art = "                            _.-'''''-._\n                          .'  _     _  '.\n                         /   (_)   (_)   \\\n                        |  ,           ,  |\n                        |  \\`.       .`/  |\n                         \\  '.`'''''`.'  /\n                          '.  `'---'`  .'\n                            '-._____.-'\n";
  mon[HAPPYFACE].win = "\nBoy, you're sure pretty joyous!\n";
  mon[HAPPYFACE].check = "Are you sure you don't want to look (j)oyful? It is the holidays, after all.\n";
  mon[HAPPYFACE].winKey = 'J';
  mon[HAPPYFACE].fought = false;

  mon[XENOMORPH].name = "Xenomorph";
  mon[XENOMORPH].ability = "\nReminds me of a movie where they used a (f)lamethrower. Happen to have one?\n";
  mon[XENOMORPH].art = "         __.,,------.._\n      ,''   _      _   '`.\n     /.__, ._  -=- _'`    Y\n    (.____.-.`      ''`   j\n     VvvvvvV`.Y,.    _.,-'       ,     ,     ,\n        Y    ||,   ''\\         ,/    ,/    ./\n        |   ,'  ,     `-..,'_,'/___,'/   ,'/   ,\n   ..  ,;,,',-''\\,'  ,  .     '     ' ''' '--,/    .. ..\n ,'. `.`---'     `, /  , Y -=-    ,'   ,   ,. .`-..||_|| ..\nff\\\\`. `._        /f ,'j j , ,' ,   , f ,  \\=\\ Y   || ||`||_..\nl` \\` `.`.'`-..,-' j  /./ /, , / , / /l \\   \\=\\l   || `' || ||...\n `  `   `-._ `-.,-/ ,' /`'/-/-/-/-'''''`.`.  `'.\\--`'--..`'_`' || ,\n            '`-_,',  ,'  f    ,   /      `._   ``._     ,  `-.`'//         ,\n          ,-''' _.,-'    l_,-'_,,'          '`-._ . '`. /|     `.'\\ ,       |\n        ,',.,-''          \\=) ,`-.         ,    `-'._`.V |       \\ // .. . /j\n        |f\\\\               `._ )-.'`.     /|         `.| |        `.`-||-\\\\/\n        l` \\`                 '`._   '`--' j          j' j          `-`---'\n         `  `                     '`,-  ,'/       ,-''  /\n                                 ,'',__,-'       /,, ,-'\n                                 Vvv'            VVv'\n";
  mon[XENOMORPH].win = "\nThat's a pretty crispy Xenomorph. Maybe that can be lunch tomorrow.\n";
  mon[XENOMORPH].check = "Are you sure you don't want to use the (f)lamethrower you just happen to have?\n";
  mon[XENOMORPH].winKey = 'F';
  mon[XENOMORPH].fought = false;

/* copypaste template
  mon[].name = "";
  mon[].ability = "";
  mon[].art = "";
  mon[].win = "";
  mon[].check = "";
  mon[].winKey = '';
  mon[].fought = false;
*/
}

void GetHome::sayHi()
{
  system("clear");

  // program greeting
  cout << "Welcome to GET HOME, a text adventure!\nWill you be able to find your way home?\n";
}

void GetHome::gameMenu()
{
  cout << "\nYou will have the option to move north, south, east, or west.\n";
  cout << "You can do this using the N, S, E, and W keys.\n";
  cout << "You can look around the room using the L key.\n";
  cout << "You can bring up this menu again using the H key.\n";
  cout << "You can quit at any time using the Q key, unless in combat!\n\n";
  this_thread::sleep_for(1500ms);
  cout << "HINT: Sometimes there might be an action to (P)erform...\n\n";
}

void GetHome::getName()
{
  cout << "Who are you, by the way? ";
  cin >> playerName;
  cout << "\nAlright " << playerName << ", now let's get home!!!\n\n";
  this_thread::sleep_for(2000ms);
  system("clear");
}

void GetHome::play(Rooms *rm, Monsters *mon)
{
  bool validMove,
    quit = false;

  // we start in the swimming pool, based on Rooms_Enum
  curRoom = POOL;
  cout << rm[curRoom].title << "\n";
  cout << rm[curRoom].desc << "\n";

  do {

    // my rooms either have a monster...
    if (rm[curRoom].monster == true)
    {

      // fight a random monster!
      fightMonster(room, monst);
      do {
        move = getMove();
        if (move != 'Q')
          validMove = playRoom(move, room, dirs);
        else
          quit = checkQuit();
      } while(!validMove && !quit);
    }

    // ...or don't
    else
    {
      move = getMove();
      if (move != 'Q')
        validMove = playRoom(move, room, dirs);
      else
        quit = checkQuit();
    }
  } while(/*!hasKeys && !hasCar &&*/!winner && !quit);
}

char GetHome::getMove()
{
  cout << "Now, what would you like to do? ";
  cin >> move;
  move = (toupper(move));
  return move;
}

void GetHome::fightMonster(Rooms *rm, Monsters *mon)
{
  bool validMonst,
    beatMonst;
  int x;

  do {
    x = (rand() % 4);
    if (mon[x].fought == false)
      validMonst = true;
    else
      validMonst = false;
  } while(!validMonst);

  mon[x].fought = true;
  rm[curRoom].monster = false;
  this_thread::sleep_for(1500ms);
  cout << "\n\n";
  cout << string(10, ' ') << mon[x].name << string(10, ' ') << "VERSUS" << string(10, ' ') << playerName << "\n\n";
  cout << mon[x].art;
  cout << mon[x].ability;

  do {
    cout << "\nWhat will you do??? ";
    cin >> move;
    move = (toupper(move));
    cout << string(80, '-') << "\n";
    if (move == mon[x].winKey)
    {
      cout << mon[x].win;
      cout << rm[curRoom].look;// << "\n";
      beatMonst = true;
    }
    else
    {
      cout << mon[x].check;
      beatMonst = false;
    }
  } while(!beatMonst);


/*
  do {
    int pickMonst = (rand() % 4);
    if (mon[pickMonst].fought == false)
    {
      cout << "\n\n";
      cout << string(10, ' ') << mon[pickMonst].name << string(10, ' ') << "VERSUS" << string(10, ' ') << playerName << "\n\n";
      cout << mon[pickMonst].art;
      cout << mon[pickMonst].ability;
      do {
        cout << "\nWhat will you do??? ";
        cin >> move;
        move = (toupper(move));
        if (move == mon[pickMonst].winKey)
        {
          cout << mon[pickMonst].win;
          beatMonst = true;
        }
        else
        {
          cout << mon[pickMonst].check;
          beatMonst = false;
        }
      } while(!beatMonst);
      validMonst = true;
      mon[pickMonst].fought = true;
    }
    else
      validMonst = false;
  } while(!validMonst);

  */
}

bool GetHome::playRoom(char move, Rooms *rm, Directions *dir)
{
  rm[curRoom].visited = true;

  if (curRoom == LOBBY && move == 'K')
  {
//    hasKeys = true;
    rm[curRoom].flag = true;
    cout << string(80, '-') << "\n";
    cout << "\nYou picked up your car keys!\n";
    return false;
  }

  else if (curRoom == PARKINGLOT0 && move == 'C' && rm[LOBBY].flag == true)
  {
//    hasCar = true;
    rm[curRoom].flag = true;
    cout << string(80, '-') << "\n";
    cout << "\nYou got in your car!\n";
    return false;
  }

  else if (curRoom == PARKINGLOT0 && move == 'C' && rm[LOBBY].flag == false)
  {
    cout << string(80, '-') << "\n";
    cout << "\nYour car is locked. Where'd you leave your keys?\n";
    return false;
  }

  // l for look
  else if (move == 'L')
  {
    if ((curRoom == LOBBY && rm[curRoom].flag == false) || (curRoom == PARKINGLOT0 && rm[curRoom].flag == false))
      cout << rm[curRoom].desc;
    else
      cout << rm[curRoom].look;
    return false;
  }

  // h for help
  else if (move == 'H')
  {
    gameMenu();
    return false;
  }

  // directionals
  else if (move == 'N' || move == 'S' || move == 'E' || move == 'W')
  {
    for (int i = 0; i < EXITS; i++)
    {
      if (move == dir[i].compass)
      {
        if (rm[curRoom].exit[i] == HOME)
          winner = checkWin(room);
        else if (rm[curRoom].exit[i] != NONE)
        {
          curRoom = rm[curRoom].exit[i];
          cout << string(80, '-') << "\n";
          cout << "\nYou are now in " << rm[curRoom].title << ".\n\n";
          if (rm[curRoom].visited == false || (curRoom == LOBBY && rm[curRoom].flag == false) || (curRoom == PARKINGLOT0 && rm[curRoom].flag == false))
            cout << rm[curRoom].desc;
          return true;
        }
        else
        {
          cout << "You can't go that way!!\n";
          return false;
        }
      }
    }
    return false;
  }

  // invalid
  else
  {
    cout << "Not valid input. If you need a reminder, enter H for help!\n";
    return false;
  }
}

bool GetHome::checkWin(Rooms *rm)
{
  if (rm[LOBBY].flag == true && rm[PARKINGLOT0].flag == true)
  {
    cout << "You made it home safe, and have your keys to get in.\n";
    this_thread::sleep_for(1500ms);
    cout << "Time to enjoy a sandwich...\n";
    this_thread::sleep_for(1500ms);
    printMeal();
    return true;
  }
  else
  {
    cout << "\nYou just realized you left your house keys in your car. Oops.\n";
    cout << "Seems like you saw your car in the parking lot.\n";
    return false;
  }
}

bool GetHome::checkQuit()
{
  cout << "Are you sure? (Y to quit, any other key continues the journey) ";
  cin >> forSure;
  forSure = (toupper(forSure));
  if (forSure == 'Y')
    return true;
  else
    return false;
}

void GetHome::printMeal()
{
  cout << string(58, ' ') << "//\n";
  cout << string(57, ' ') << "//\n";
  cout << string(41, ' ') << "_______________//___\n";
  cout << string(39, ' ') << ".(______________//____).\n";
  cout << string(39, ' ') << "|              /       |\n";
  cout << string(39, ' ') << "|. . . . . . . / . . . |\n";
  cout << string(39, ' ') << "\\ . . . . . ./. . . . ./\n";
  cout << string(40, ' ') << "|           /        |\n";
  cout << string(20, ' ') << "_.---._             |::......./.........:|\n";
  cout << string(16, ' ') << "_.-~       ~-._         |:::::/  \\::/  \\:::::|\n";
  cout << string(12, ' ') << "_.-~               ~-._     |:::::\\__/::\\__/:::::|\n";
  cout << string(8, ' ') << "_.-~                       ~---.;::::::::::::::::::::|\n";
  cout << string(4, ' ') << "_.-~                                 ~\\::::\\______/::::::|\n";
  cout << string(1, ' ') << ".-~                                    _.;::::::::::::::::::/\n";
  cout << string(1, ' ') << ":-._                               _.-~ ./:::::::::::::::::|\n";
  cout << string(1, ' ') << "`-._~-._                   _..__.-~ _.-~|::/:::::::::::::::|\n";
  cout << string(2, ' ') << "/  ~-._~-._              / .__..--~----.WWWWWWWWWWWWWWWWWW'\n";
  cout << string(1, ' ') << "\\_____(_;-._\\.        _.-~_/       ~).. . \\\n";
  cout << string(4, ' ') << "/(_____  \\`--...--~_.-~______..-+_______)\n";
  cout << string(2, ' ') << ".(_________/`--...--~/    _/           /\\\n";
  cout << string(1, ' ') << "/-._     \\_     (___./_..-~__.....__..-~./\n";
  cout << string(1, ' ') << "`-._~-._   ~\\--------~  .-~_..__.-~ _.-~\n";
  cout << string(5, ' ') << "~-._~-._ ~---------'  / .__..--~\n";
  cout << string(9, ' ') << "~-._\\.        _.-~_/\n";
  cout << string(13, ' ') << "\\`--...--~_.-~\n";
  cout << string(14, ' ') << "`--...--~\n";
}

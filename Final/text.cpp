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
  bool visited,
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
    art;
  bool fought;
} monst[MONS];

class RoomVars
{
public:
  // current room, based on room number and Rooms_Enum
  int curRoom;

  // booleans for having keys and car
  bool hasKeys = false,
    hasCar = false,

    // gamer over for losing to a monster
    over = false,

    // winner for, well, yeah
    winner = false;

  // input for movement
  char move;

  // function prototypes
  void setRooms(Rooms *rm);
  void setDirs(Directions *dir);
  void setMons(Monsters *mon);
  void sayHi();
  void gameMenu();
  void play(Rooms *rm);
  bool makeMove(char move, Rooms *rm, Directions *dir);
  void printMeal();
};

int main()
{
  RoomVars game;

  // random seed for monster usage
  srand(time(0));

  // establish the layout of the rooms and exit directions
  game.setRooms(room);
  game.setDirs(dirs);
  game.sayHi();
  this_thread::sleep_for(2s);
  game.gameMenu();
  this_thread::sleep_for(2s);

  // start in the swimming pool, based on Rooms_Enum
  game.curRoom = POOL;

  game.play(room);
}

void RoomVars::setRooms(Rooms *rm)
{
  rm[POOL].title = "Swimming Pool";
  rm[POOL].desc = "You are floating in a swimming pool.\nThere is an exit to the south, but something doesn't feel right.\nIs there something in the water with you?\n";
  rm[POOL].look = "You are floating in the swimming pool. Still.\nThere is an exit to the south.\n";
  rm[POOL].visited = true;
  rm[POOL].monster = true;
  rm[POOL].exit[N] = NONE;
  rm[POOL].exit[S] = LOBBY;
  rm[POOL].exit[E] = NONE;
  rm[POOL].exit[W] = NONE;

  rm[LOBBY].title = "Lobby";
  rm[LOBBY].desc = "You are in a hotel lobby. Did you stay here last night? It's all such a blur.\nYou see your car keys on the ground. Weird.\nNow, where did you park?\nOh, there's a parking lot to the south.\n";
  rm[LOBBY].look = "You are in the hotel lobby.\nThe swimming pool is to the north.\nThe parking lot is to the south.\n";
  rm[LOBBY].visited = false;
  rm[LOBBY].monster = false;
  rm[LOBBY].exit[N] = POOL;
  rm[LOBBY].exit[S] = PARKINGLOT1;
  rm[LOBBY].exit[E] = NONE;
  rm[LOBBY].exit[W] = NONE;

  rm[PARKINGLOT0].title = "Parking Lot A";
  rm[PARKINGLOT0].desc = "You're in Parking Lot A.\nParking Lot B is to the east, and the rest is fenced.\nThat car over there looks familiar, though...\n";
  rm[PARKINGLOT0].look = "You're in Parking Lot A.\nParking Lot B is to the east, and the rest is fenced.\n";
  rm[PARKINGLOT0].visited = false;
  rm[PARKINGLOT0].monster = false;
  rm[PARKINGLOT0].exit[N] = NONE;
  rm[PARKINGLOT0].exit[S] = NONE;
  rm[PARKINGLOT0].exit[E] = PARKINGLOT1;
  rm[PARKINGLOT0].exit[W] = NONE;

  rm[PARKINGLOT1].title = "Parking Lot B";
  rm[PARKINGLOT1].desc = "You're in Parking Lot B.\nTo the north is the lobby.\nTo the south is the street.\nTo the east is the parking lot fence.\nTo the west is Parking Lot A.\n";
  rm[PARKINGLOT1].look = "You're in Parking Lot B.\nTo the north is the lobby.\nTo the south is the street.\nTo the east is the parking lot fence.\nTo the west is Parking Lot A.\n";
  rm[PARKINGLOT1].visited = false;
  rm[PARKINGLOT1].monster = false;
  rm[PARKINGLOT1].exit[N] = LOBBY;
  rm[PARKINGLOT1].exit[S] = STREET1;
  rm[PARKINGLOT1].exit[E] = NONE;
  rm[PARKINGLOT1].exit[W] = PARKINGLOT0;

  rm[BRIDGE].title = "Collapsed Bridge";
  rm[BRIDGE].desc = "You're at the edge of a collapsed bridge.\nThe only way out is the street to the east, but something's in the rubble...\n";
  rm[BRIDGE].look = "You're at the edge of the collapsed bridge.\n";
  rm[BRIDGE].visited = false;
  rm[BRIDGE].monster = true;
  rm[BRIDGE].exit[N] = NONE;
  rm[BRIDGE].exit[S] = NONE;
  rm[BRIDGE].exit[E] = STREET0;
  rm[BRIDGE].exit[W] = NONE;

  rm[STREET0].title = "West Street";
  rm[STREET0].desc = "You're on the western-most part of the street.\nA bridge is to the west.\nThe street continues to the east, but your way is blocked!\n";
  rm[STREET0].look = "You're on the western-most part of the street.\nA bridge is to the west.\nThe street continues to the east.\n";
  rm[STREET0].visited = false;
  rm[STREET0].monster = true;
  rm[STREET0].exit[N] = NONE;
  rm[STREET0].exit[S] = NONE;
  rm[STREET0].exit[E] = STREET1;
  rm[STREET0].exit[W] = BRIDGE;

  rm[STREET1].title = "Mid Street";
  rm[STREET1].desc = "You're on the middle of the street.\nThe street continues to the east and west.\nThe parking lot is to the north.\n";
  rm[STREET1].look = "You're on the middle of the street.\nThe street continues to the east and west.\nThe parking lot is to the north.\n";
  rm[STREET1].visited = false;
  rm[STREET1].monster = false;
  rm[STREET1].exit[N] = PARKINGLOT1;
  rm[STREET1].exit[S] = NONE;
  rm[STREET1].exit[E] = STREET2;
  rm[STREET1].exit[W] = STREET0;

  rm[STREET2].title = "East Street";
  rm[STREET2].desc = "You're on the eastern-most part of the street.\nThe street continues to the west.\nYou see your house to the east! But what's that...\n";
  rm[STREET2].look = "You're on the eastern-most part of the street.\nThe street continues to the west.\nYou see your house to the east!";
  rm[STREET2].visited = false;
  rm[STREET2].monster = true;
  rm[STREET2].exit[N] = NONE;
  rm[STREET2].exit[S] = NONE;
  rm[STREET2].exit[E] = HOME;
  rm[STREET2].exit[W] = STREET1;

  rm[HOME].title = "Home";
  rm[HOME].desc = "You made it home, safe! Time for a sandwich...";
  rm[HOME].look = "";
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
  rm[].visited = false;
  rm[].monster = ;
  rm[].exit[N] = ;
  rm[].exit[S] = ;
  rm[].exit[E] = ;
  rm[].exit[W] = ;
*/
}

void RoomVars::setDirs(Directions *dir)
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

void RoomVars::setMons(Monsters *mon)
{
  mon[DINOSAUR].name = "Dinosaur":
  mon[DINOSAUR].ability = "This thing is huge!\nRemember that one movie though?\nSome of the big ones don't see very well...\n";
  mon[DINOSAUR].art = "DINO ART";
  mon[DINOSAUR].fought = false;

  mon[ZOMBIE].name = "Zombie";
  mon[ZOMBIE].ability = "Ew. How fast can you run?\n";
  mon[ZOMBIE].art = "ZOMBIE ART";
  mon[ZOMBIE].fought = false;

  mon[HAPPYFACE].name = "Happy Face Emoji";
  mon[HAPPYFACE].ability = "All he wants is to bring happiness!\n";
  mon[HAPPYFACE].art = "HAPPY ART";
  mon[HAPPYFACE].fought = false;

  mon[XENOMORPH].name = "Xenomorph";
  mon[XENOMORPH].ability = "Reminds me of a movie where they used a flamethrower. Happen to have one?";
  mon[XENOMORPH].art = "XENO ART";
  mon[XENOMORPH].fought = false;
}

void RoomVars::sayHi()
{
  system("clear");

  // program greeting
  cout << "Welcome to GET HOME, a text adventure!\nWill you be able to find your way home?\n";
}

void RoomVars::gameMenu()
{
  cout << "\nYou will have the option to move north, south, east, or west.\n";
  cout << "You can do this using the N, S, E, and W keys.\n";
  cout << "You can look around the room using the L key.\n";
  cout << "You can bring up this menu again using the H key.\n";
  cout << "You can quit at any time using the Q key.\n\n";
  cout << "HINT: Sometimes there might be an action to (P)erform...\n\n";
  cout << "Now, let's get home!!!\n\n\n";
}

void RoomVars::play(Rooms *rm)
{
  char forSure;

  cout << rm[curRoom].title << "\n";
  cout << rm[curRoom].desc << "\n";

  do {
    cout << "What would you like to do? ";
    cin >> move;
    move = (toupper(move));
    if (move != 'Q')
    {
      winner = makeMove(move, room, dirs);
    }
    else
    {
      cout << "Are you sure you'd like to quit? (\"y\" to quit) ";
      cin >> forSure;
      forSure = (toupper(forSure));
      if (forSure == 'Y')
        break;
    }
  } while(!winner);
}

bool RoomVars::makeMove(char move, Rooms *rm, Directions *dir)
{
  // look around if L is input
  if (move == 'L')
  {
    cout << rm[curRoom].look << "\n";
    return false;
  }

  else if (move == 'H')
  {
    gameMenu();
    return false;
  }

  // otherwise, check for a valid move
  else if (move == 'N' || move == 'S' || move == 'E' || move == 'W')
  {
    // cycle through the exits
    for (int i = 0; i < EXITS; i++)
    {

      // check what to do with the entered direction
      if (move == dir[i].compass)
      {

        // move the player if the room has an exit
        if (rm[curRoom].exit[i] != NONE)
        {

          // check if we're home or not
          if (rm[curRoom].exit[i] == HOME)
          {

            // did you get your car?
            if ((hasCar == false))
            {
              cout << "\nYou just realized you left your house keys in your car. Oops.\n";
              cout << "Seems like you saw your car in the parking lot.\n";
              return false;
            }
            else
            {
              cout << "\nYou made it home, safe! Time for a sandwich...\n";
              printMeal();
              return true;
            }
          }
          else
          {
            // change to the new room
            curRoom = rm[curRoom].exit[i];

            // mark the new room as being visited, changes text output on look
            rm[curRoom].visited = true;

            // print the name of the new room
            cout << "\nYou are now in " << rm[curRoom].title << ".\n";

            // print the description of the new room
            cout << rm[curRoom].desc << "\n";
          }
        }
        else
        {
          cout << "You can't go that way!\n\n";
        }
      }
    }
    return false;
  }


  // if we're in the lobby, allow picking up of keys
  // else if ()

  // if we're in Parking Lot A, allow entering the car
  // else if ()

  // otherwise invalid input
  else
  {
    cout << "Not valid input. If you need a reminder, enter H for help!\n";
    return false;
  }
}

void RoomVars::printMeal()
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

/*
bool checkWin(Rooms *rm)
{
  if (rm[curRoom] = HOME)
    winner = true;
  return winner;
}
*/

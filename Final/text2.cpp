#include <iostream>
#include <string>
#include <cctype>
using namespace std;

/*
pool = 0
lobby = 1
parking = 2, 3
bridge = 4
street = 5, 6, 7
home = 8
*/
enum Rooms_Enum {POOL, LOBBY, PARKINGLOT0, PARKINGLOT1, BRIDGE, STREET0, STREET1, STREET2, HOME};

// north = 0, south = 1, east = 2, west = 3
enum Dirs_Enum {N, S, E, W};

// use sentinel if we don't have an exit from a room
const int NONE = -1;

// number of rooms
const int ROOMS = 9;

// number of potential exit directions
const int EXITS = 4;

struct Rooms
{
  string title;
  string desc;
  string look;
  bool visited;
  int exit[EXITS];
} room[ROOMS];

struct Directions
{
  char compass;
  int dirNum;
} dirs[EXITS];

class RoomVars
{
public:
  // current room, based on room number and Rooms_Enum
  int curRoom;

  // booleans for quitting, or winning
  bool hasCar = false,
    over = false,
    winner = false;

  // input for movement
  char move;

  // function prototypes
  void setRooms(Rooms *rm);
  void setDirs(Directions *dir);
  void sayHi();
  void gameMenu();
  void play();
  bool makeMove(char move, Rooms *rm, Directions *dir);
  void printMeal();
//  bool checkWin(Rooms *rm);
};

int main()
{
  RoomVars game;

  srand(time(0));

  // establish the layout of the rooms and exit directions
  game.setRooms(room);
  game.setDirs(dirs);
  game.sayHi();
  game.gameMenu();

  // start in the swimming pool, based on Rooms_Enum
  game.curRoom = POOL;
  game.play();
}

void RoomVars::setRooms(Rooms *rm)
{
  rm[POOL].title = "Swimming Pool";
  rm[POOL].desc = "You are floating in a swimming pool.\nThere is an exit to the south, but something doesn't feel right.\nIs there something in the water with you?\n";
  rm[POOL].look = "You are floating in the swimming pool. Still.\nThere is an exit to the south\n";
  rm[POOL].visited = false;
  rm[POOL].exit[N] = NONE;
  rm[POOL].exit[S] = LOBBY;
  rm[POOL].exit[E] = NONE;
  rm[POOL].exit[W] = NONE;

  rm[LOBBY].title = "Lobby";
  rm[LOBBY].desc = "You are in a hotel lobby. Did you stay here last night? It's all such a blur.\nYou see your car keys on the ground. Weird. You pick them up.\nNow, where did you park?\n";
  rm[LOBBY].visited = false;
  rm[LOBBY].exit[N] = POOL;
  rm[LOBBY].exit[S] = PARKINGLOT1;
  rm[LOBBY].exit[E] = NONE;
  rm[LOBBY].exit[W] = NONE;

  rm[PARKINGLOT0].title = "Parking Lot - West";
  rm[PARKINGLOT0].desc = "You're in the western half of the large parking lot.\nThat car over there looks familiar...\n";
  rm[PARKINGLOT0].visited = false;
  rm[PARKINGLOT0].exit[N] = NONE;
  rm[PARKINGLOT0].exit[S] = NONE;
  rm[PARKINGLOT0].exit[E] = PARKINGLOT1;
  rm[PARKINGLOT0].exit[W] = NONE;

  rm[PARKINGLOT1].title = "Parking Lot - East";
  rm[PARKINGLOT1].desc = "You're in Parking Lot B.\nTo the north is the lobby.\nTo the south is the street.\nTo the east is the parking lot fence.\nTo the west is Parking Lot A.\n";
  rm[PARKINGLOT1].visited = false;
  rm[PARKINGLOT1].exit[N] = LOBBY;
  rm[PARKINGLOT1].exit[S] = STREET1;
  rm[PARKINGLOT1].exit[E] = NONE;
  rm[PARKINGLOT1].exit[W] = PARKINGLOT0;

  rm[BRIDGE].title = "Collapsed Bridge";
  rm[BRIDGE].desc = "";
  rm[BRIDGE].visited = false;
  rm[BRIDGE].exit[N] = NONE;
  rm[BRIDGE].exit[S] = NONE;
  rm[BRIDGE].exit[E] = STREET0;
  rm[BRIDGE].exit[W] = NONE;

  rm[STREET0].title = "Street";
  rm[STREET0].desc = "";
  rm[STREET0].visited = false;
  rm[STREET0].exit[N] = NONE;
  rm[STREET0].exit[S] = NONE;
  rm[STREET0].exit[E] = STREET1;
  rm[STREET0].exit[W] = BRIDGE;

  rm[STREET1].title = "Street";
  rm[STREET1].desc = "";
  rm[STREET1].visited = false;
  rm[STREET1].exit[N] = PARKINGLOT1;
  rm[STREET1].exit[S] = NONE;
  rm[STREET1].exit[E] = STREET2;
  rm[STREET1].exit[W] = STREET0;

  rm[STREET2].title = "Street";
  rm[STREET2].desc = "";
  rm[STREET2].visited = false;
  rm[STREET2].exit[N] = NONE;
  rm[STREET2].exit[S] = NONE;
  rm[STREET2].exit[E] = HOME;
  rm[STREET2].exit[W] = STREET1;

  rm[HOME].title = "Home";
  rm[HOME].desc = "";
  rm[HOME].visited = false;
  rm[HOME].exit[N] = NONE;
  rm[HOME].exit[S] = NONE;
  rm[HOME].exit[E] = NONE;
  rm[HOME].exit[W] = STREET2;

/* copypaste template
  rm[].title = "";
  rm[].desc = "";
  rm[].look = "";
  rm[].visited = false;
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
}

void RoomVars::play()
{
  do {
    cout << "What would you like to do? ";
    cin >> move;
    move = (toupper(move));
    if (move != 'Q')
    {
      winner = makeMove(move, room, dirs);
    }
  } while(!winner);
}

bool RoomVars::makeMove(char move, Rooms *rm, Directions *dir)
{
  // look around if L is input
  if (move == 'L')
  {
    cout << rm[curRoom].desc << "\n";
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
          curRoom = rm[curRoom].exit[i];
          if (curRoom == HOME)
          {
            if ((hasCar == false))
            {
              cout << "You just realized you left your house keys in your car. Oops.\n";
              return false;
            }
            else
            {
              cout << "You made it home, safe! Time for a sandwich...\n";
              printMeal();
              return true;
            }
          }
          else
            cout << "You are now in " << rm[curRoom].title << ".\n";
        }
        else
        {
          cout << "You can't go that way!\n";
        }
      }
    }
    return false;
  }

  else
  {
    cout << "Not valid input.\n";
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

// g++ -std=c++14 -g -Wall b2dl.cpp


#include <iostream>
#include <string>
using namespace std;

// declare prototypes
void sayHi();
string generalMenu();
string raiseItAll(string menuSelection);
bool checkA1(string &);
bool checkA13(string &);
bool checkA100(string &);
bool checkA159(string &);
bool checkA161(string &);
bool checkA167(string &);
bool checkA173(string &);
bool checkA212(string &);
bool checkA232(string &);
bool checkA290(string &);
void a1();
void a13();
void a100();
void a159();
void a161();
void a167();
void a173();
void a212();
void a232();
void a290();

// start the book!
int main()
{
  char startOver;

  // program greeting
  sayHi();

  do {
    a1();

    cout << "The end!\n\n";

    cout << "Would you like to play again?\n";
    cout << "Enter N to quit, or any other letter to continue.\n";
    cin >> startOver;

  } while (toupper(startOver) != 'N');

  return 0;
}

void sayHi()
{
  cout << "Welcome to Butler to the Dark Lord, a text adventure!\n\n";
}

string generalMenu()
{
  string menuSelection;
  cout << "Which path is yours?\n";
  cout << "Enter your choice by number or first word.\n";
  cin >> menuSelection;
  cout << "\n";
  return menuSelection;
}

string raiseItAll(string menuSelection)
{
	for (int count = 0; count <= static_cast<int>(menuSelection.length()); count ++)
		menuSelection[count] = toupper(menuSelection[count]);
	return menuSelection;
}

bool checkA1(string &checkIt)
{
  bool acceptSelection;
  if (checkIt == "1" || checkIt == "2" || checkIt == "IT'S" || checkIt == "SURELY")
    acceptSelection = true;
  return acceptSelection;
}

bool checkA13(string &checkIt)
{
  bool acceptSelection;
  if (checkIt == "1" || checkIt == "2" || checkIt == "3" || checkIt == "ARE" || checkIt == "IF" || checkIt == "OR")
    acceptSelection = true;
  return acceptSelection;
}

bool checkA100(string &checkIt)
{
  bool acceptSelection;
  if (checkIt == "1" || checkIt == "ONWARDS")
    acceptSelection = true;
  return acceptSelection;
}

bool checkA159(string &checkIt)
{
  bool acceptSelection;
  if (checkIt == "1" || checkIt == "DONE")
    acceptSelection = true;
  return acceptSelection;
}

bool checkA161(string &checkIt)
{
  bool acceptSelection;
  if (checkIt == "1" || checkIt == "DONE")
    acceptSelection = true;
  return acceptSelection;
}

bool checkA167(string &checkIt)
{
  bool acceptSelection;
  if (checkIt == "1" || checkIt == "ONWARDS")
    acceptSelection = true;
  return acceptSelection;
}

bool checkA173(string &checkIt)
{
  bool acceptSelection;
  if (checkIt == "1" || checkIt == "2" || checkIt == "DO" || checkIt == "OR")
    acceptSelection = true;
  return acceptSelection;
}

bool checkA212(string &checkIt)
{
  bool acceptSelection;
  if (checkIt == "1" || checkIt == "NICELY")
    acceptSelection = true;
  return acceptSelection;
}

bool checkA232(string &checkIt)
{
  bool acceptSelection;
  if (checkIt == "1" || checkIt == "2" || checkIt == "THE" || checkIt == "OR")
    acceptSelection = true;
  return acceptSelection;
}

bool checkA290(string &checkIt)
{
  bool acceptSelection;
  if (checkIt == "1" || checkIt == "EXCELLENT")
    acceptSelection = true;
  return acceptSelection;
}

void a1()
{
  bool acceptSelection;
  string menuSelection;

  cout << "  Well, Mr Artanon, look at you. Who would have thought that the\n";
  cout << "son of a lowly spider farmer could rise to such esteemed heights? Yet\n";
  cout << "here you are, standing in the kitchens of Cayfax Castle, dressed in\n";
  cout << "the finest livery onyx can buy. For you, sir, are butler to Malacandros,\n";
  cout << "Dark Lord of all Nocturnia. The flames of fireplaces tickle suspended\n";
  cout << "pots, which thicken the air with competing scents. Workers along\n";
  cout << "stone benches busily chop and kill ingredients - nothing but the\n";
  cout << "best for his lordship, of course. In the centre of the chamber a great\n";
  cout << "oven blazes, its cracked chimney oozing smoke. \"Ah, Mr Artanon,\"\n";
  cout << "simpers Repugnis, the head cook. He’s a fat goblin who samples too\n";
  cout << "many of his own creations, as evidenced by his bulging belly and the\n";
  cout << "delta of stains down his apron. \"I’m roasting his Horrendousness a\n";
  cout << "prime briar beast basted in snake oil. Mmm-mmm! The intestines are\n";
  cout << "stuffed with rotten apple and breadcrumb, and I’ve shoved a carrot\n";
  cout << "up its arse.\" You arch an eyebrow, for Mal is already situated upstairs\n";
  cout << "in the dining hall. With midday waning, he will be growing hungry.\n";
  cout << "\"And just how long,\" you ask, \"do you intend to keep his lordship\n";
  cout << "staring at an empty plate?\" Repugnis titters nervously, and glances\n";
  cout << "towards the oven. \"Good sir, a roast takes as long as a roast takes. If\n";
  cout << "I stoke the flames any hotter the skin will crisp to charcoal. At best I\n";
  cout << "could aim for a rare cut?\"\n\n";

  cout << "1. \"It’s you who’ll get a rare cut across that corpulent neck of yours\n";
  cout << "if you don’t speed things along, you feckless blob of festering lard.\"\n\n";

  cout << "2. \"Surely in such an industrious kitchen, there must be a starter or\n";
  cout << "two ready to send along and sate His Abhorentness’s appetite?\"\n\n";

  do {
    menuSelection = generalMenu();
    menuSelection = raiseItAll(menuSelection);
    acceptSelection = checkA1(menuSelection);
  } while (!acceptSelection);

  if (menuSelection == "1" || menuSelection == "IT'S")
    a100();
  else
    a167();
}

void a13()
{
  bool acceptSelection;
  string menuSelection;

  cout << "  Feeling dangerous, Mr Artanon? You move past Mal to Captain\n";
  cout << "Haiken and, using a pair of tongs fashioned to look like crow’s claws,\n";
  cout << "start placing rat heads onto his plate. As you do, you glance surrep-\n";
  cout << "titiously at Mal, wondering if you have irritated him by serving his\n";
  cout << "guest first - he is not exactly known for his good manners - but he\n";
  cout << "does not seem to have noticed. At any rate, your first footman, Kalag\n";
  cout << "- a young man who shows much promise - hops to action, to lay sliv-\n";
  cout << "ers of slug meat on Mal’s plate. \"Er...\" says Haiken, his meaty hand\n";
  cout << "skimming the tableware. You realize he is uncertain about what,\n";
  cout << "amongst the array of cutlery laid out on either side of his plate, is the\n";
  cout << "correct implement to use for rat heads.\n\n";

  cout << "1. Are you a DIPLOMAT? (turn to A212)\n\n";

  cout << "2. If not, do you simply inform him which is the proper rat-head-\n";
  cout << "eating-fork? (turn to A159)\n\n";

  cout << "3. Or do you let him flounder? (turn to A173)\n\n";

  do {
    menuSelection = generalMenu();
    menuSelection = raiseItAll(menuSelection);
    acceptSelection = checkA13(menuSelection);
  } while (!acceptSelection);

  if (menuSelection == "1" || menuSelection == "ARE")
    a212();
  else if (menuSelection == "2" || menuSelection == "IF")
    a159();
  else
    a173();
}

void a100()
{
  bool acceptSelection;
  string menuSelection;

  cout << "  Repugnis turns a paler shade of green, and gulps. \"I beg you, Mr\n";
  cout << "Artanon, stay your hand. I’m sure that something must be ready.\"\n";
  cout << "The cook glances around and spots a bench at which several trays are\n";
  cout << "being assembled. \"Ah!\" he says. \"How about some pickled rat heads\n";
  cout << "and carpaccio of slug?\" You scowl, long enough to make Repugnis\n";
  cout << "quiver, then turn and snap at some lurking footmen. \"Get those trays\n";
  cout << "up to his lordship without delay!\" The footmen spring into action,\n";
  cout << "seizing the trays and heading for the door. \"Thank you, sir,\" says\n";
  cout << "Repugnis. \"The roast will not be far behind, I promise.\" \"See that it\n";
  cout << "isn’t,\" you reply, \"or the next item on the menu might be goblin stew.\"\n";
  cout << "It seems you are an INTIMIDATOR.\n\n";

  cout << "1. Onwards, Mr Artanon.\n\n";

  do {
    menuSelection = generalMenu();
    menuSelection = raiseItAll(menuSelection);
    acceptSelection = checkA100(menuSelection);
  } while (!acceptSelection);

  a232();
}

void a159()
{
  bool acceptSelection;
  string menuSelection;

  cout << "  You clear your throat and speak softly. \"That little one there is\n";
  cout << "your rat-head-eating-fork, my lord.\" Despite your attempt to be sub-\n";
  cout << "tle, Mal registers the exchange and chortles. Haiken, embarrassed\n";
  cout << "to be found ignorant, frowns. \"I know what fork to use, you stupid\n";
  cout << "butler! Begone before I stab you in the eye with it.\" With your lords\n";
  cout << "served, you move back from the table to remain in waiting. Somehow\n";
  cout << "you doubt Haiken’s bedclothes will be properly turned.\n\n";

  cout << "1. Done\n\n";

  do {
    menuSelection = generalMenu();
    menuSelection = raiseItAll(menuSelection);
    acceptSelection = checkA159(menuSelection);
  } while (!acceptSelection);

}

void a161()
{
  bool acceptSelection;
  string menuSelection;

  cout << "  You move away from Haiken, whose hand still hovers uncertainly\n";
  cout << "over the cutlery, to serve Mal rat heads. Finally Haiken makes a\n";
  cout << "decision and picks up a carapace-cracking-spork. Mal chuckles at\n";
  cout << "his ignorance. \"By Stygias, Captain - have you been in the field so\n";
  cout << "long that you’ve forgotten the basic functions of tableware?\" Haiken\n";
  cout << "grimaces. \"Pardon me, your Pettiness. I may have had a noble birth,\n";
  cout << "yet life as a soldier puts me out of touch with certain niceties. We\n";
  cout << "tend to eat with our hands.\" Mal laughs. \"Well, let us not stand on\n";
  cout << "ceremony, Captain! I am happy to do it your way!\" Mal picks up a\n";
  cout << "rat head with his hand and shovels it into his mouth. Haiken happily\n";
  cout << "follows suit, munching and cracking skulls with his teeth. Inwardly,\n";
  cout << "you give a sigh. No doubt with such messy fingers, Mal will stain the\n";
  cout << "dragon bone. Why, you have often wondered, would anyone fashion\n";
  cout << "a dining chair out of such easily blemished material as bleached\n";
  cout << "porous bone? Just as you fear, Mal leans back to rest his grubby mitts\n";
  cout << "upon the armrests. The CHAIR IS DIRTY. You move back to the wall\n";
  cout << "while your lords eat, to remain in waiting. A butler’s work is never\n\n";

  cout << "1. Done\n\n";

  do {
    menuSelection = generalMenu();
    menuSelection = raiseItAll(menuSelection);
    acceptSelection = checkA161(menuSelection);
  } while (!acceptSelection);

}

void a167()
{
  bool acceptSelection;
  string menuSelection;

  cout << "  Repugnis nods eagerly, which ripples his many chins. \"Yes sir,\n";
  cout << "of course! Let me see now...\" He glances around and spots a bench\n";
  cout << "where several platters are being assembled. \"Ah! How about some\n";
  cout << "pickled rat heads and delectable carpaccio of slug?\" \"Very good,\" you\n";
  cout << "say. \"I am told that Captain Haiken is particularly partial to rat. But\n";
  cout << "see that you hurry along now, Repugnis. I don’t need to remind you\n";
  cout << "that his lordship’s patience is virtually non-existent.\" \"Of course, sir,\n";
  cout << "of course.\" You click your fingers at some waiting footmen and they\n";
  cout << "leap to action, seizing the platters and heading for the door. It seems\n";
  cout << "you are a DIPLOMAT.\n\n";

  cout << "1. Onwards, Mr Artanon.\n\n";

  do {
    menuSelection = generalMenu();
    menuSelection = raiseItAll(menuSelection);
    acceptSelection = checkA167(menuSelection);
  } while (!acceptSelection);

  a232();
}

void a173()
{
  bool acceptSelection;
  string menuSelection;

  cout << "  As they gnash away, Mal and Haiken discuss the Captain’s recent\n";
  cout << "raid on the town of Greenflower. \"Honestly,\" says Haiken, \"those\n";
  cout << "wretched Brightlanders are so easily slaughtered, sometimes I almost\n";
  cout << "feel bad for them.\" Mal laughs at this hilarious joke. \"Ha! That’s a\n";
  cout << "good one, Captain. But tell me, what of your primary objective?\"\n";
  cout << "\"I am pleased to report success, my lord.\" \"You have brought me a\n";
  cout << "virgin?\" \"She languishes in your dungeon even now - lovely, virtu-\n";
  cout << "ous and ripe for sacrifice.\" \"Excellent. My skywatchers predict a full\n";
  cout << "moon in three nights time - perfect conditions for the ceremony.\"\n";
  cout << "Footsteps sound at the dining hall entrance, and a goblin messen-\n";
  cout << "ger, whom you recognize as Peedy, enters wearing a feathered hat\n";
  cout << "and carrying a scroll. Mal’s gaze slides to him. \"What is it?\" Peedy\n";
  cout << "clears his throat. \"Apologies for the interruption, Your Atrocious-\n";
  cout << "ness. I bring you word from Vorganis Castle.\" \"Oh?\" Mal’s tone is so\n";
  cout << "instantly cold that the very temperature of the room seems to drop.\n";
  cout << "\"Er... yes, my lord. Lord Nefarian accepts your kind invitation to\n";
  cout << "attend the Stygias Ceremony, and intends to arrive tomorrow morn-\n";
  cout << "ing.\" Mal’s eyes narrow. You know he does not care for his cousin\n";
  cout << "Nefarian, not least because the man is next in line to the throne. Ne-\n";
  cout << "farian’s presence at the ceremony, however, must be tolerated, for he\n";
  cout << "is a powerful lord in his own right, with many allies amongst Noc-\n";
  cout << "turnia’s nobility - a fact which Mal does not enjoy being reminded\n";
  cout << "of. \"Why bring me such news at lunch?\" he growls. \"It has put a foul\n";
  cout << "taste in my mouth and sullied my food.\" He drums his fingers on the\n";
  cout << "dragon bone armrest, and fiery sparks flare at his fingertips. Peedy\n";
  cout << "quails, for he knows that Mal is prone to taking out his anger on the\n";
  cout << "bearers of bad news. It would be a shame, however (and a staffing\n";
  cout << "issue), to lose a competent messenger to a moment of ill temper over\n";
  cout << "something that really isn’t his fault.\n\n";

  cout << "1. Do you attempt to intercede on Peedy’s behalf?\n\n";

  cout << "2. Or abandon him to his miserable fate?\n\n";

  do {
    menuSelection = generalMenu();
    menuSelection = raiseItAll(menuSelection);
    acceptSelection = checkA173(menuSelection);
  } while (!acceptSelection);
}

void a212()
{
  bool acceptSelection;
  string menuSelection;

  cout << "  You clear your throat very slightly, and Haiken glances up at you.\n";
  cout << "As you move your hand back from his plate, you let your finger rest\n";
  cout << "momentarily on the appropriate rat-head-eating fork. Haiken under-\n";
  cout << "stands, and gives you a relieved look. Mal is too busy shoveling slug\n";
  cout << "meat into his gullet to notice the exchange, so HAIKEN IS GRATE-\n";
  cout << "FUL. You add some rat heads to Mal’s plate and move back from the\n";
  cout << "table to take a place in waiting.\n\n";

  cout << "1. Nicely done, Mr Artanon. (turn to A161)\n\n";

  do {
    menuSelection = generalMenu();
    menuSelection = raiseItAll(menuSelection);
    acceptSelection = checkA212(menuSelection);
  } while (!acceptSelection);

  a161();
}

void a232()
{
  bool acceptSelection;
  string menuSelection;

  cout << "  You overtake the footmen along a corridor lit by stuttering can-\n";
  cout << "dles, and lead them through a wide archway into the airy dining hall.\n";
  cout << "Great windows stand open along one wall, looking out upon a pleas-\n";
  cout << "ant view of circling lizard-birds cannibalizing their young. Down\n";
  cout << "the length of the hall runs an immense marble table, at the head of\n";
  cout << "which the Dark Lord Malacandros reclines in a chair of elaborately\n";
  cout << "carved dragon bone. He is a gaunt man with darting eyes and sharp\n";
  cout << "features, currently dressed in a very tasteful grey robe (which you\n";
  cout << "helped him get into this morning), his black hair clasped in a pony-\n";
  cout << "tail down his back. To his right sits Captain Haiken, one of his fa-\n";
  cout << "vored brutes, a well muscled orc in polished steel. \"Ah, Mr Artanon,\"\n";
  cout << "says Mal, \"I was beginning to worry we’d been forgotten.\" He gives\n";
  cout << "you a thin smile, which warns you he is very close to becoming irked.\n";
  cout << "You bow deeply. \"My humble apologies, oh Intolerant One. Repugnis\n";
  cout << "is putting the final touches on today’s main course, and you know\n";
  cout << "what a perfectionist he is. In the meantime,\" you whisk a platter from\n";
  cout << "one of the footmen, \"here are some starters to whet your appetites.\"\n";
  cout << "As you move toward the head of the table, Haiken licks his lips. \"Rat\n";
  cout << "heads!\" he exclaims. \"My favorite.\"\n\n";

  cout << "Who will you serve first?\n";
  cout << "1. The enthusiastic Captain Haiken? (turn to A13)\n\n";

  cout << "2. Or your master, Malacandros? (turn to A290)\n\n";

  do {
    menuSelection = generalMenu();
    menuSelection = raiseItAll(menuSelection);
    acceptSelection = checkA232(menuSelection);
  } while (!acceptSelection);

  if (menuSelection == "1" || menuSelection == "THE")
    a13();
  else
    a290();
}

void a290()
{
  bool acceptSelection;
  string menuSelection;

  cout << "  As is only fitting, you serve your master first. As you place the\n";
  cout << "largest and juiciest rat heads before him, your first footman Kalag\n";
  cout << "- a young fellow who shows much promise - moves to Haiken and\n";
  cout << "starts laying slug meat on his plate. \"Er,\" says Haiken, \"not too much\n";
  cout << "slug for me, thank you - I have an allergy.\" Mal, who is in mid-chew,\n";
  cout << "scoffs, and shoots a shard of half-chewed rat skull out of his nostril\n";
  cout << "to ping off a wine glass. \"Rut me, Haiken,\" he says. \"I’ve seen you\n";
  cout << "rip the throat from a charging horse, yet you can’t stomach a little\n";
  cout << "slug?\" Haiken seems embarrassed. \"They give me hives, my lord.\"\n";
  cout << "\"Ha! Well, better get over there with some of his precious rat heads,\n";
  cout << "Mr Artanon.\" You do as you are bid, and place the remaining rat\n";
  cout << "heads on Haiken’s plate. They are a little on the smaller side, and\n";
  cout << "you notice a wistful look in Haiken’s eye as Mal lifts another plump\n";
  cout << "one to his mouth. With your lords served, you move back from the\n";
  cout << "table to remain in waiting.\n\n";

  cout << "1. Excellent posture, Mr Artanon.\n\n";

  do {
    menuSelection = generalMenu();
    menuSelection = raiseItAll(menuSelection);
    acceptSelection = checkA290(menuSelection);
  } while (!acceptSelection);

  a161();
}

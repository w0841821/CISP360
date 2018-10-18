/* 










A232
You overtake the footmen along a corridor lit by stuttering can-
dles, and lead them through a wide archway into the airy dining hall.
Great windows stand open along one wall, looking out upon a pleas-
ant view of circling lizard-birds cannibalizing their young. Down
the length of the hall runs an immense marble table, at the head of
which the Dark Lord Malacandros reclines in a chair of elaborately
carved dragon bone. He is a gaunt man with darting eyes and sharp
features, currently dressed in a very tasteful grey robe (which you
helped him get into this morning), his black hair clasped in a pony-
tail down his back. To his right sits Captain Haiken, one of his fa-
vored brutes, a well muscled orc in polished steel. "Ah, Mr Artanon,"
says Mal, "I was beginning to worry we’d been forgotten." He gives
you a thin smile, which warns you he is very close to becoming irked.
You bow deeply. "My humble apologies, oh Intolerant One. Repugnis
is putting the final touches on today’s main course, and you know
what a perfectionist he is. In the meantime," you whisk a platter from
one of the footmen, "here are some starters to whet your appetites."
As you move toward the head of the table, Haiken licks his lips. "Rat
heads!" he exclaims. "My favorite."
Who will you serve first?
1. The enthusiastic Captain Haiken? (turn to A13)
2. Or your master, Malacandros? (turn to A290)
5butler to the dark lord (b2dl)




A290
As is only fitting, you serve your master first. As you place the
largest and juiciest rat heads before him, your first footman Kalag
- a young fellow who shows much promise - moves to Haiken and
starts laying slug meat on his plate. "Er," says Haiken, "not too much
slug for me, thank you - I have an allergy." Mal, who is in mid-chew,
scoffs, and shoots a shard of half-chewed rat skull out of his nostril
to ping off a wine glass. "Rut me, Haiken," he says. "I’ve seen you
rip the throat from a charging horse, yet you can’t stomach a little
slug?" Haiken seems embarrassed. "They give me hives, my lord."
"Ha! Well, better get over there with some of his precious rat heads,
Mr Artanon." You do as you are bid, and place the remaining rat
heads on Haiken’s plate. They are a little on the smaller side, and
you notice a wistful look in Haiken’s eye as Mal lifts another plump
one to his mouth. With your lords served, you move back from the
table to remain in waiting.
1. Excellent posture, Mr Artanon. (turn to A161)


A159
You clear your throat and speak softly. "That little one there is
your rat-head-eating-fork, my lord." Despite your attempt to be sub-
tle, Mal registers the exchange and chortles. Haiken, embarrassed
to be found ignorant, frowns. "I know what fork to use, you stupid
butler! Begone before I stab you in the eye with it." With your lords
served, you move back from the table to remain in waiting. Somehow
you doubt Haiken’s bedclothes will be properly turned.
6butler to the dark lord (b2dl)
1. Done


A161
You move away from Haiken, whose hand still hovers uncertainly
over the cutlery, to serve Mal rat heads. Finally Haiken makes a
decision and picks up a carapace-cracking-spork. Mal chuckles at
his ignorance. "By Stygias, Captain - have you been in the field so
long that you’ve forgotten the basic functions of tableware?" Haiken
grimaces. "Pardon me, your Pettiness. I may have had a noble birth,
yet life as a soldier puts me out of touch with certain niceties. We
tend to eat with our hands." Mal laughs. "Well, let us not stand on
ceremony, Captain! I am happy to do it your way!" Mal picks up a
rat head with his hand and shovels it into his mouth. Haiken happily
follows suit, munching and cracking skulls with his teeth. Inwardly,
you give a sigh. No doubt with such messy fingers, Mal will stain the
dragon bone. Why, you have often wondered, would anyone fashion
a dining chair out of such easily blemished material as bleached
porous bone? Just as you fear, Mal leans back to rest his grubby mitts
upon the armrests. The CHAIR IS DIRTY. You move back to the wall
while your lords eat, to remain in waiting. A butler’s work is never
1. Done







Display
Just indicate the game is finished.
*/



/*

This problem is taken from a "find your path" book of the same
name. The idea is you read a passage of text and then decide which
of the presented options you will choose next. If you make good de-
cisions, you will win (or in this case, survive). We can represent part
of this book with a flowchart, see figure 1. Paragraphs are indicated
with "A" + a number. These also appear at the end of each passage
and direct the reader where to read next. You are going to modify
that with a menu option. The reader will select a number and pro-
gram execution will jump to that location. You will also notice words
in ALLCAPS. These are boolean variables reflecting your status as
you progress through the story. You will need to keep track of these.

"C" Specification Bundle.
1. Program has all the elements discussed in the style guide.

// Specification C1 - Individual Functions
Each text passage (A1, A167, etc) is within it’s own function. Call the functions to progress through the story. You don’t need to
comment all the functions with this specification comment, just the first one. Hint: Call the functions by the passage identifier - makes
your code easier to red.

// Specification C2 - Simple menu
Use a simple menu to call the next function. Just add this comment to the first one; you don’t need to comment all of them. This can be numeric.

// Specification B1 - Booleans
When done, display the current state of all the BOOLEAN variables.

// Specification B2 - Path
Display the path the client took through the story (use the A1, A167, etc. not the menu options) when the story is completed.

// Specification B3 - General Menu
Code the menu in a general function which accepts up to 3 strings and returns an integer value for the chosen option. Call this from each function to generate your menu at the bottom of the text.

//Specification B4 - Valid choices only
In A13, there is one option which cannot be taken unless a boolean variable is set. If the variable is set, only offer this option, suppress the other 2.

// Specification B5 – Function Prototype
Use function prototypes and code the functions under main().

// Specification A1 - Input Validation
Use input validation to allow only the correct menu values. Re-prompt until proper input is entered.

// Specification A2 - No Globals
Do not use global variables to pass data around the program. Yes, you can put this comment where global’s would normally go.

// Specification A3 - Game loop
Wrap the program in a loop which prompts you to go again when you finish.

// Specification A4 - <>
Add one feature of your own choosing.


*/




// b2dl.cpp
// Erroll Abrahamian, CISP 360
// 10-28-2018

#include <iostream>
// #include <iomanip>
// #include <string>
using namespace std;

// function prototypes
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
void display();
int checkMenu();
int checkMenu3();

int menuSelect;

int main()
{
	a1();

	return 0;
}

int checkMenu()
{
	cout << "Enter 1 or 2.\n";
	cin >> menuSelect;
	return menuSelect;
}

int checkMenu3()
{
	cout << "Enter 1, 2, or 3.\n";
	cin >> menuSelect;
	return menuSelect;
}

void a1()
{
	cout << "Well, Mr Artanon, look at you. Who would have thought that the son of a lowly\n";
	cout << "spider farmer could rise to such esteemed heights? Yet here you are, standing\n";
	cout << "in the kitchens of Cayfax Castle, dressed in the finest livery onyx can buy.\n";
	cout << "For you, sir, are butler to Malacandros, Dark Lord of all Nocturnia. The flames\n";
	cout << "of fireplaces tickle suspended pots, which thicken the air with competing\n";
	cout << "scents. Workers along stone benches busily chop and kill ingredients - nothing\n";
	cout << "but the best for his lordship, of course. In the centre of the chamber a great\n";
	cout << "oven blazes, its cracked chimney oozing smoke. ’Ah, Mr Artanon,’ simpers\n";
	cout << "Repugnis, the head cook. He’s a fat goblin who samples too many of his own\n";
	cout << "creations, as evidenced by his bulging belly and the delta of stains down his\n";
	cout << "apron. ’I’m roasting his Horrendousness a prime briar beast basted in snake\n";
	cout << "oil. Mmm-mmm! The intestines are stuffed with rotten apple and breadcrumb, and I’ve shoved a carrot up its arse.’ You arch an eyebrow, for Mal is already situated upstairs in the dining hall. With midday waning, he will be growing hungry. ’And just how long,’ you ask, ’do you intend to keep his lordship staring at an empty plate?’ Repugnis titters nervously, and glances towards the oven. ’Good sir, a roast takes as long as a roast takes. If I stoke the flames any hotter the skin will crisp to charcoal. At best I could aim for a rare cut?’\n";
	cout << "What is your reply?\n\n";

	cout << "1. ’It’s you who’ll get a rare cut across that corpulent neck of yours if you\n";
	cout << "don’t speed things along, you feckless blob of festering lard.’\n";
	cout << "2. ’Surely in such an industrious kitchen, there must be a starter or two ready\n";
	cout << "to send along and sate His Abhorentness’s appetite?’\n";

	checkMenu();
	if (menuSelect == 1)
		a100();
	else if (menuSelect == 2)
		a167();
	else checkMenu();
}

void a13()
{
	cout << "Here's 13.\n";

	cout << "Feeling dangerous, Mr Artanon? You move past Mal to Captain Haiken and, using\n";
	cout << "a pair of tongs fashioned to look like crow’s claws, start placing rat heads\n";
	cout << "onto his plate. As you do, you glance surreptitiously at Mal, wondering if you\n";
	cout << "have irritated him by serving his guest first - he is not exactly known for his\n";
	cout << "good manners - but he does not seem to have noticed. At any rate, your first\n";
	cout << "footman, Kalag - a young man who shows much promise - hops to action, to lay\n";
	cout << "slivers of slug meat on Mal’s plate. \"Er...\" says Haiken, his meaty hand\n";
	cout << "skimming the tableware. You realize he is uncertain about what, amongst the\n";
	cout << "array of cutlery laid out on either side of his plate, is the correct implement\n";
	cout << "to use for rat heads.\n\n";

	cout << "1. Are you a DIPLOMAT? (turn to A212)\n";
	cout << "2. If not, do you simply inform him which is the proper rat-head-eating-fork? (turn to A159)\n";
	cout << "3. Or do you let him flounder? (turn to A173)\n";

	checkMenu3();
	if (menuSelect == 1)
		a212();
	else if (menuSelect == 2)
		a159();
	else if (menuSelect == 3)
		a173();
	else checkMenu();
}

void a100()
{
	cout << "Here's a100.\n";

	A100
Repugnis turns a paler shade of green, and gulps. "I beg you, Mr
Artanon, stay your hand. I’m sure that something must be ready."
The cook glances around and spots a bench at which several trays are
being assembled. "Ah!" he says. "How about some pickled rat heads
and carpaccio of slug?" You scowl, long enough to make Repugnis
quiver, then turn and snap at some lurking footmen. "Get those trays
up to his lordship without delay!" The footmen spring into action,
4butler to the dark lord (b2dl)
seizing the trays and heading for the door. "Thank you, sir," says
Repugnis. "The roast will not be far behind, I promise." "See that it
isn’t," you reply, "or the next item on the menu might be goblin stew."
It seems you are an INTIMIDATOR.
1. Onwards, Mr Artanon. (turn to A232)

	checkMenu();
	if (menuSelect == 1)
		a100();
	else if (menuSelect == 2)
		a167();
	else checkMenu();

	a232();
}

void a212()
{
	cout << "Here's a212.\n";

	A212
You clear your throat very slightly, and Haiken glances up at you.
As you move your hand back from his plate, you let your finger rest
momentarily on the appropriate rat-head-eating fork. Haiken under-
stands, and gives you a relieved look. Mal is too busy shoveling slug
meat into his gullet to notice the exchange, so HAIKEN IS GRATE-
FUL. You add some rat heads to Mal’s plate and move back from the
table to take a place in waiting.
1. Nicely done, Mr Artanon. (turn to A161)

	checkMenu();
	if (menuSelect == 1)
		a100();
	else if (menuSelect == 2)
		a167();
	else checkMenu();

	a161();
}

void a159()
{
	cout << "Here's a159.\n";

	checkMenu();
	if (menuSelect == 1)
		a100();
	else if (menuSelect == 2)
		a167();
	else checkMenu();

	display();
}

void a161()
{
	cout << "Here's a161.\n";

	checkMenu();
	if (menuSelect == 1)
		a100();
	else if (menuSelect == 2)
		a167();
	else checkMenu();

	display();
}

void a167()
{
	cout << "Here's a167.\n";

	A167
Repugnis nods eagerly, which ripples his many chins. ’Yes sir,
of course! Let me see now...’ He glances around and spots a bench
where several platters are being assembled. ’Ah! How about some
pickled rat heads and delectable carpaccio of slug?’ ’Very good,’ you
say. ’I am told that Captain Haiken is particularly partial to rat. But
see that you hurry along now, Repugnis. I don’t need to remind you
that his lordship’s patience is virtually non-existent.’ ’Of course, sir,
of course.’ You click your fingers at some waiting footmen and they
leap to action, seizing the platters and heading for the door. It seems
you are a DIPLOMAT.
1. Onwards, Mr Artanon. (turn to A232)

	checkMenu();
	if (menuSelect == 1)
		a100();
	else if (menuSelect == 2)
		a167();
	else checkMenu();

	a232();
}

void a173()
{
	cout << "Here's a173.\n";

	A173
As they gnash away, Mal and Haiken discuss the Captain’s recent
raid on the town of Greenflower. "Honestly," says Haiken, "those
wretched Brightlanders are so easily slaughtered, sometimes I almost
feel bad for them." Mal laughs at this hilarious joke. "Ha! That’s a
good one, Captain. But tell me, what of your primary objective?"
"I am pleased to report success, my lord." "You have brought me a
virgin?" "She languishes in your dungeon even now - lovely, virtu-
ous and ripe for sacrifice." "Excellent. My skywatchers predict a full
moon in three nights time - perfect conditions for the ceremony."
Footsteps sound at the dining hall entrance, and a goblin messen-
ger, whom you recognize as Peedy, enters wearing a feathered hat
and carrying a scroll. Mal’s gaze slides to him. "What is it?" Peedy
clears his throat. "Apologies for the interruption, Your Atrocious-
ness. I bring you word from Vorganis Castle." "Oh?" Mal’s tone is so
instantly cold that the very temperature of the room seems to drop.
"Er... yes, my lord. Lord Nefarian accepts your kind invitation to
attend the Stygias Ceremony, and intends to arrive tomorrow morn-
ing." Mal’s eyes narrow. You know he does not care for his cousin
Nefarian, not least because the man is next in line to the throne. Ne-
farian’s presence at the ceremony, however, must be tolerated, for he
7butler to the dark lord (b2dl)
is a powerful lord in his own right, with many allies amongst Noc-
turnia’s nobility - a fact which Mal does not enjoy being reminded
of. "Why bring me such news at lunch?" he growls. "It has put a foul
taste in my mouth and sullied my food." He drums his fingers on the
dragon bone armrest, and fiery sparks flare at his fingertips. Peedy
quails, for he knows that Mal is prone to taking out his anger on the
bearers of bad news. It would be a shame, however (and a staffing
issue), to lose a competent messenger to a moment of ill temper over
something that really isn’t his fault.
1. Do you attempt to intercede on Peedy’s behalf? (Done)
2. Or abandon him to his miserable fate? (Done)
In either case, both paths lead to the end of the homework, too.

	checkMenu();
	if (menuSelect == 1)
		a100();
	else if (menuSelect == 2)
		a167();
	else checkMenu();

	display();
}

void a232()
{
	cout << "Here's a232.\n";

	checkMenu();
	if (menuSelect == 1)
		a100();
	else if (menuSelect == 2)
		a167();
	else checkMenu();

	a290();
	a13();
}

void a290()
{
	cout << "Here's a290.\n";

	checkMenu();
	if (menuSelect == 1)
		a100();
	else if (menuSelect == 2)
		a167();
	else checkMenu();

	a161();
}

void display()
{
	cout << "The end.\n";
}
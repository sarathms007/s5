//Cegaratte smokers problem
/*Three smokers are sitting around a table. One of them  has tobacco, another has cigarette papers, and the third one has matches ( each one has a different ingredient required to make and smoke a cigarette).

There is also a non-smoking arbiter. The arbiter enables the smokers to make their cigarettes by arbitrarily selecting two of the smokers, taking one item out of each of their supplies, and placing the items on the table. He then notifies the third smoker that he has done this. The third smoker removes the two items from the table and uses them (along with his own supply) to make a cigarette, which he smokes for a while. Meanwhile, the arbiter, seeing the table empty, again chooses two smokers at random and places their items on the table. This process continues forever.
           A smoker only begins to roll a new cigarette once he is finished smoking the last one. If the arbiter places tobacco and paper on the table while the match man is smoking, the tobacco and paper will remain untouched on the table until the match man is finished with his cigarette and collects them. */


//Solution

//code
enum Ingredients /* Enum representing the ingredients */
{
None,
Paper,
Tobacco,
Matches
};

/* Structure representing a Smoker & Agent process */
typedef struct smoker
{
char SmokerID[25];
int Item;
}SMOKER;

typedef struct agent
{
char AgentID[25];
int Item1;
int Item2;
}AGENT;
char* GetIngredientName(int Item)
{
if(Item == Paper)
return "Paper";
else if(Item == Tobacco)
return "Tobacco";
else if(Item == Matches)
return "Matches";
}
void GetAgentIngredients(AGENT* agent)
{
/* Simulate random generation of ingredients*/
agent->Item1=random(3);
agent->Item1++;
while(1)
{
agent->Item2=random(3);
agent->Item2++;
if(agent->Item1 != agent->Item2)
break;
}
printf("\nAgent Provides Ingredients- %s,%s\n\n:" ,GetIngredientName(agent->Item1),GetIngredientName(agent->Item2));
}
void GiveIngredientToSmoker(AGENT*agent,SMOKER* smoker)
{
int index=0;
while(smoker[index].Item !=NULL)
{
if((smoker[index].Item !=agent->Item1)&&(smoker[index].Item != agent->Item2));
{
printf("\nSmoker - \%s\"-is smoking his cigarette\n\n", smoker[index].SmokerID);
agent->Item1=None;
agent->Item2=None;
break;
}
index++;
}
}
void main()
{
/*Create the processes required -1 Agent, 3 Smokers */
AGENT agent;
SMOKER smoker[4] = {	{"SmokerWithPaper",Paper},
{"SmokerWithTobacco",Tobacco},
{"SmokerWithMatches",Matches},{"\0",None}};
int userChoice=0;
strcpy(agent.AgentID,"Agent");
agent.Item1=None;
agent.Item2=None;
while(1)
{
GetAgentIngredients(&agent);
GiveIngredientToSmoker(&agent,smoker);
printf("Press ESC to exit or any key to continue\n\n");
//userChoice=getch();
scanf("%d", &userChoice);
if(userChoice ==27)
break;
}
}
